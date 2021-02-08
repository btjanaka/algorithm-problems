// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) jesse-and-cookies
// Title: Jesse and Cookies
// Link: https://www.hackerrank.com/challenges/jesse-and-cookies/problem
// Idea: Throw everything in a heap and keep doing the operation described.
// Note that runtime is n log n because the number of cookies decreases by one
// each time we do the operation (since we combine two cookies into one).
// Difficulty: easy
// Tags: heap, priority-queue
#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, k, x;
  cin >> n >> k;
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < n; ++i) {
    cin >> x;
    pq.push(x);
  }

  int ops = 0;
  while (!pq.empty() && pq.top() < k) {
    int a = pq.top();
    pq.pop();
    if (pq.empty()) break;  // Might run out in the middle.
    int b = pq.top();
    pq.pop();
    pq.push(a + 2 * b);
    ++ops;
  }

  if (pq.empty()) {
    // No cookies.
    cout << -1 << endl;
  } else {
    cout << ops << endl;
  }

  return 0;
}
