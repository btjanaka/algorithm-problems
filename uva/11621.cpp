// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11621
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

ll series[500];
int series_size;

void generate_series() {
  series_size = 0;
  ll base2 = 1;
  for (int i = 0; i < 32; ++i) {
    for (ll j = 1; base2 * j <= 1L << 31; j *= 3) {
      series[series_size++] = base2 * j;
    }
    base2 *= 2;
  }
  sort(series, series + series_size);
}

int main() {
  int n;
  generate_series();
  while (GET(n) && n) {
    printf("%lld\n", *lower_bound(series, series + series_size, n));
  }
  return 0;
}
