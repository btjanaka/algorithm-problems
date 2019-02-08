// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10755
#include <bits/stdc++.h>
using namespace std;

// x, y, z
long long nums[22][22][22];

void printnums(int a, int b, int c) {
  printf("==========\n");
  for (int x = 0; x < a; ++x) {
    for (int y = 0; y < b; ++y) {
      for (int z = 0; z < c; ++z) {
        printf("%2lld ", nums[x][y][z]);
      }
      putchar('\n');
    }
    putchar('\n');
  }
  printf("==========\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    // Input
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    for (int x = 0; x < a; ++x)
      for (int y = 0; y < b; ++y)
        for (int z = 0; z < c; ++z) scanf("%lld", &nums[x][y][z]);

    // printnums(a, b, c);

    // Do 2d cumulative sums on each level. Then for every possible 2d rectangle
    // possible, apply Kadane's algorithm to find max prism for that rectangle.
    // Run-time:
    // * Calculation of 2d cumulative sums is O(n^3)
    // * Calculation of prism sums is O(n^5) --> n^4 to go through all
    //   rectangles, O(n) to calculate for each rectangle

    // 2d cumulative sums
    for (int x = 0; x < a; ++x) {
      for (int y = 0; y < b; ++y) {
        for (int z = 0; z < c; ++z) {
          long long val = nums[x][y][z];
          if (y > 0) val += nums[x][y - 1][z];
          if (z > 0) val += nums[x][y][z - 1];
          if (y > 0 && z > 0) val -= nums[x][y - 1][z - 1];
          nums[x][y][z] = val;
        }
      }
    }

    // printnums(a, b, c);

    // Sums over each rectangle
    long long mx = LONG_MIN;
    for (int y0 = 0; y0 < b; ++y0) {
      for (int z0 = 0; z0 < c; ++z0) {
        for (int y = y0; y < b; ++y) {
          for (int z = z0; z < c; ++z) {
            long long curr = 0;
            for (int x = 0; x < a; ++x) {
              // Calculate value of this rectangle at this level
              long long rect = nums[x][y][z];
              if (y0 > 0) rect -= nums[x][y0 - 1][z];
              if (z0 > 0) rect -= nums[x][y][z0 - 1];
              if (y0 > 0 && z0 > 0) rect += nums[x][y0 - 1][z0 - 1];
              // printf("%lld (%d, %d)-(%d, %d)\n", rect, y0, z0, y, z);

              // Add on value
              curr += rect;
              if (curr > mx) mx = curr;
              if (curr < 0) curr = 0;
            }
          }
        }
      }
    }

    // Results
    printf("%lld\n", mx);
    if(t) putchar('\n');
  }
  return 0;
}
