// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) marcs-cakewalk
// Title: Marc's Cakewalk
// Link: https://www.hackerrank.com/challenges/marcs-cakewalk/problem
// Idea: Match the highest calorie counts to the lowest powers of 2 (i.e. sort
// the calorie counts).
// Difficulty: easy
// Tags: greedy
#include <bits/stdc++.h>
using namespace std;

int main() {
  // Input the numbers and sort them.
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  sort(arr, arr + n);

  // Count up the total.
  long long tot = 0;
  for (long long i = 0; i < n; ++i)
    // Lowest powers of 2 are assigned to highest calorie counts (which are at
    // the end of the sorted array).
    tot += (1ull << i) * arr[n - i - 1];
  cout << tot << endl;
  return 0;
}
