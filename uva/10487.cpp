// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10487
#include <bits/stdc++.h>
using namespace std;

int arr[10000];
int sums[1001000];

int find_closest(int n, int q) {
  int min_diff = 1000000000;
  int closest = -1;
  int diff;
  for (int i = 0; i < n; ++i) {
    diff = abs(sums[i] - q);
    if (diff < min_diff) {
      min_diff = diff;
      closest = sums[i];
    }
  }
  return closest;
}

int main() {
  int n;
  for (int i = 1; scanf("%d", &n) > 0 && n > 0; ++i) {
    // Receive input and sort
    for (int j = 0; j < n; ++j) scanf("%d", &arr[j]);
    int l = 0;
    for (int j = 0; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        sums[l++] = arr[j] + arr[k];
      }
    }
    sort(sums, sums + l);

    // Process queries
    int m;
    scanf("%d", &m);
    int q;
    printf("Case %d:\n", i);
    for (int j = 0; j < m; ++j) {
      scanf("%d", &q);
      printf("Closest sum to %d is %d.\n", q, find_closest(l, q));
    }
  }
  return 0;
}
