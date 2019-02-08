// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11332
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

int sum_digits(int n) {
  int digit_sum = 0;
  for (; n > 0; n /= 10) {
    digit_sum += n % 10;
  }
  if (digit_sum < 10) {
    return digit_sum;
  } else {
    return sum_digits(digit_sum);
  }
}

int main() {
  int n;
  while (GET(n) && n != 0) {
    printf("%d\n", sum_digits(n));
  }
  return 0;
}
