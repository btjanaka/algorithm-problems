// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10474
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d", arr[_i]);                    \
      }                                           \
    }                                             \
    putchar('\n');                                \
  }
#define PBS(n, len) /*Print a bitset*/ \
  {                                    \
    for (int _i = 0; _i < len; ++_i) { \
      putchar(n % 2 + '0');            \
      n /= 2;                          \
    }                                  \
    putchar('\n');                     \
  }
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
#define INF 2147483647
typedef long long ll;
using namespace std;

int nums[12000];

int main() {
  int n, q;
  for (int ca = 1; GET(n) && GET(q) && n && q; ++ca) {
    printf("CASE# %d:\n", ca);
    FOR(i, 0, n) GET(nums[i]);
    sort(nums, nums + n);

    int qu;
    FOR(i, 0, q) {
      GET(qu);
      int* found = lower_bound(nums, nums + n, qu);
      if (found != nums + n && *found == qu) {
        printf("%d found at %d\n", qu, int(found - nums + 1));
      } else {
        printf("%d not found\n", qu);
      }
    }
  }
  return 0;
}
