// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10718
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

int main() {
  unsigned int n, l, u;
  while (scanf("%u %u %u", &n, &l, &u) > 0) {
    // Greedy solution: At each bit, check if the bit is needed to satisfy the
    // lower limit, which is done by seeing what would happen if the bit was not
    // added but all bits after it were turned on. If turning off this bit would
    // make the number too low, it needs to be turned on. Also, if n has a 0 at
    // this bit, check if the bit can be added without exceeding the limit.
    unsigned int m = 0;
    for (int i = 31; i >= 0; --i) {
      if ((m + (1u << i) - 1) < l) {
        m |= 1u << i;
      } else if (!(n & (1u << i)) && (m | (1u << i)) <= u) {
        m |= 1u << i;
      }
    }
    printf("%u\n", m);
  }
  return 0;
}
