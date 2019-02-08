// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 108
#include <bits/stdc++.h>
using namespace std;

int arr[110][110];

int main() {
  // Input
  int n;
  while (scanf("%d", &n) > 0) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", &arr[i][j]);
        if (i > 0)
          arr[i][j] += arr[i - 1][j];  // Add the rectangle from the top
        if (j > 0)
          arr[i][j] += arr[i][j - 1];  // Add the rectangle from the left
        if (i > 0 && j > 0) arr[i][j] -= arr[i - 1][j - 1];
      }
    }

    // Print out board
    // for (int i = 0; i < n; ++i) {
    // for (int j = 0; j < n; ++j)
    // printf("%2d ", arr[i][j]);
    // putchar('\n');
    //}

    // Calculate the sums
    int mx = -1000000000;
    for (int x0 = 0; x0 < n; ++x0) {
      for (int y0 = 0; y0 < n; ++y0) {
        for (int x = x0; x < n; ++x) {
          for (int y = y0; y < n; ++y) {
            // Calculate sum; compare to mx
            // x0 and y0 mark left top corner of matrix.
            // x and y mark bottom right corner of matrix.
            int area = arr[x][y];
            if (x0 > 0) area -= arr[x0 - 1][y];
            if (y0 > 0) area -= arr[x][y0 - 1];
            if (x0 > 0 && y0 > 0) area += arr[x0 - 1][y0 - 1];
            if (area > mx) mx = area;
          }
        }
      }
    }

    // Print result
    printf("%d\n", mx);
  }
  return 0;
}
