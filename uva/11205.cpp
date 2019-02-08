// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11205
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d\n", arr[_i]);                  \
      }                                           \
    }                                             \
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

int nums[110];

int main() {
  int t;
  GET(t);
  while (t--) {
    int p, n;
    scanf("%d %d\n", &p, &n);
    memset(nums, 0, sizeof(nums));
    // Store each combo as a bitset
    FOR(i, 0, n) {
      FOR(j, 0, p) {
        int x;
        GET(x);
        nums[i] |= x << j;
      }
    }

    // Go through all possible subsets of all p bits. If all the numbers are
    // unique for a certain subset, count the number of bits in it and compare
    // to min_bits.
    int min_bits = INF;
    FOR(i, 0, 1 << p) {
      bool unique = true;
      FOR(j, 0, n) {
        FOR(k, j + 1, n) { unique &= (nums[j] & i) != (nums[k] & i); }
      }
      if (unique) {
        int bits = 0;
        for (int j = i; j > 0; j /= 2) {
          if (j % 2 != 0) ++bits;
        }
        min_bits = min(min_bits, bits);
      }
    }

    printf("%d\n", min_bits);
  }
  return 0;
}
