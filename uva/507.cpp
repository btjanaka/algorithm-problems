// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 507
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int roads[20010];

int main() {
  int b;
  scanf("%d", &b);
  for (int r = 1; r <= b; ++r) {
    // Input
    int s;
    scanf("%d", &s);
    for (int i = 0; i < s - 1; ++i) scanf("%d", &roads[i]);

    // Find max sum - Kadane's algorithm
    int mx = INT_MIN;
    int mx_i, mx_j;
    int curr = 0;
    int i = 0, j = 0;
    for (int k = 0; k < s - 1; ++k) {
      curr += roads[k];
      if (curr > mx) {
        j = k + 1;
        mx = curr;
        mx_i = i;
        mx_j = j;
      }
      if (curr == mx) {
        // Break ties for longest segment
        j = k + 1;
        if (mx_j - mx_i < j - i) {
          mx_j = j;
          mx_i = i;
        }
      }
      if (curr < 0) {
        // Reset if curr is < 0 because curr will simply drag down any future
        // sums - hence it is better to simply start over.
        curr = 0;
        i = k + 1;
      }
    }

    // Output
    if (mx <= 0)
      printf("Route %d has no nice parts\n", r);
    else
      printf("The nicest part of route %d is between stops %d and %d\n", r,
             mx_i + 1, mx_j + 1);
  }
}
