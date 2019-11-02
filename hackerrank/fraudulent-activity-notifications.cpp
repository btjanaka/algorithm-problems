// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) fraudulent-activity-notifications
// Title: Fraudulent Activity Notifications
// Link:
// https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem
// Idea: Use a "MedianQueue" data structure that uses the idea of two heaps to
// keep track of the median, while using a queue to keep track of which elements
// are oldest.
// Difficulty: medium
// Tags: data-structures, implementation
#include <bits/stdc++.h>

using namespace std;

// A data structure that keeps track of a median of a set of numbers as well as
// the "age" of each number. Based around the idea of having two heaps that keep
// track of the median. A queue tells how long each number has been in the data
// structure.
struct MedianQueue {
  void removeOldest() {
    int x = q_.front();
    q_.pop();
    // Remove the oldest number and re-adjust the sizes - we always want the
    // smaller half to be at least as big.
    if (larger_half_.find(x) != larger_half_.end()) {
      larger_half_.erase(larger_half_.find(x));
      if (larger_half_.size() < smaller_half_.size() - 1) {
        larger_half_.insert(*smaller_half_.begin());
        smaller_half_.erase(smaller_half_.begin());
      }
    } else {
      smaller_half_.erase(smaller_half_.find(x));
      if (smaller_half_.size() < larger_half_.size()) {
        smaller_half_.insert(*larger_half_.begin());
        larger_half_.erase(larger_half_.begin());
      }
    }
  }

  // Add a new number.
  void add(int x) {
    q_.push(x);
    larger_half_.insert(x);
    if (larger_half_.size() > smaller_half_.size()) {
      int y = *larger_half_.begin();
      larger_half_.erase(larger_half_.begin());
      smaller_half_.insert(y);
    } else {
      int y = *larger_half_.begin();
      larger_half_.erase(larger_half_.begin());
      smaller_half_.insert(y);
      larger_half_.insert(*smaller_half_.begin());
      smaller_half_.erase(smaller_half_.begin());
    }
  }

  // Return 2 x median.
  int doubleMedian() {
    if (smaller_half_.size() == larger_half_.size()) {
      return *smaller_half_.begin() + *larger_half_.begin();
    } else {
      return 2 * *smaller_half_.begin();
    }
  }

  // Multisets are used instead of priority queues because we need to search in
  // order to remove the oldest element. Multisets are used instead of sets
  // because there may be duplicate values.
  queue<int> q_;
  multiset<int> larger_half_;
  multiset<int, greater<int>>
      smaller_half_;  // should be at least as large as larger_half_
};

// Driver for the mq.
int main() {
  int n, d;
  cin >> n >> d;
  MedianQueue mq;

  // Populate mq with the first d entries.
  for (int i = 0; i < d; ++i) {
    int x;
    cin >> x;
    mq.add(x);
  }

  // Go through the rest of the entries and check for warning days.
  int tot = 0;
  for (int i = d; i < n; ++i) {
    int x;
    cin >> x;
    tot += x >= mq.doubleMedian();
    mq.removeOldest();
    mq.add(x);
  }

  cout << tot << endl;
  return 0;
}
