// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) crush
// Title: Array Manipulation
// Link: https://www.hackerrank.com/challenges/crush/problem
// Idea: Not quite easy - you can't brute force because that's O(n^2), so you
// instead have to maintain a series of events that tell you, at each index, how
// much you should be adding.
// Difficulty: medium
// Tags: arrays
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  // Read and cache additions.
  int n, t;
  GET(n);
  GET(t);
  std::vector<ll> arr(n, 0);
  std::vector<ii> events;  // {index, amount}
  int a, b, k;
  for (int i = 0; i < t; ++i) {
    GET(a);
    GET(b);
    GET(k);
    events.push_back({a - 1, k});  // Indicates to start adding at idx a
    events.push_back({b, -k});     // Indicates to stop adding after idx b
  }
  sort(events.begin(), events.end());

  // Apply additions. O(2k + n)
  int arr_idx = 0;
  ll add_amt = 0;
  for (const auto& e : events) {
    // Add until we get to the next event
    while (arr_idx != e.first) arr[arr_idx++] += add_amt;
    add_amt += e.second;
  }

  printf("%lld\n", *max_element(arr.begin(), arr.end()));
  return 0;
}
