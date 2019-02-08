// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 1047
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  for (int _i = 0; _i < len; ++_i) {              \
    if (_i != len - 1) {                          \
      printf("%d ", arr[_i]);                     \
    } else {                                      \
      printf("%d\n", arr[_i]);                    \
    }                                             \
  }
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
typedef long long ll;
using namespace std;

// Note: towers all 0-indexed here
int tower[25];            // Amount for each tower
int t[15];                // How many towers in this index of the list
int common_list[15][25];  // List of towers with this number in common
int num_common[15];       // Number in common
int res;                  // Bitset for results
int subset;               // Temporary set before results

int main() {
  int n, x, m;  // x = actual towers
  for (int c = 1; scanf("%d %d", &n, &x) && n > 0 && x > 0; ++c) {
    // Input
    FOR(i, 0, n) GET(tower[i]);
    GET(m);
    FOR(i, 0, m) {
      GET(t[i]);
      FOR(j, 0, t[i]) {
        GET(common_list[i][j]);
        --common_list[i][j];
      }
      GET(num_common[i]);
    }

    // Find all subsets of the n towers that contain x towers. Based on these
    // subsets, calculate number that would be included in this attempt, and
    // check against max.
    res = 0;
    int max_cus = 0;
    int limit = (1 << n) - 1;
    FORe(i, 1, limit) {
      // Count number of towers in this set while adding up normal counts
      subset = i;
      int x_count = 0;
      int cus = 0;
      FOR(j, 0, n) {
        bool cmp = i & (1 << j);
        x_count += cmp;
        if (cmp) cus += tower[j];
      }
      if (x_count != x) continue;

      // Subtract intersections
      // Count up number of shared for each tower entry, and subtract off the
      // excess - for instance if 3 regions share an area and are present in
      // this set subtract 2 times the number of people in the region.
      FOR(j, 0, m) {
        int shared = 0;
        FOR(k, 0, t[j]) {
          // i.e. check if the bit indicated by common_list[j][k] is on in
          // subset
          if (1 << common_list[j][k] & subset) ++shared;
        }
        if (shared > 1) cus -= (shared - 1) * num_common[j];
      }

      // Compare
      if (cus > max_cus) {
        max_cus = cus;
        res = subset;
      }
    }

    // Output
    printf("Case Number  %d\n", c);
    printf("Number of Customers: %d\n", max_cus);
    printf("Locations recommended:");
    FOR(i, 0, n) if ((1 << i) & res) printf(" %d", i + 1);
    PLN;
    PLN;
  }
  return 0;
}
