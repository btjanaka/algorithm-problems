// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10483
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

// Generate all 25600 sums beforehand :)
// Check if a sum is not present by checking if the first entry is still 0
vector<array<int, 3>> sums[26000];

int main() {
  int lo;
  int hi;
  float lo_f;
  float hi_f;
  scanf("%f %f", &lo_f, &hi_f);
  lo = lo_f * 100;
  hi = hi_f * 100;

  // Precalculate
  //
  // Use these equations:
  //
  // 10^4 * (a + b + c) = a * b * c (to derive, start with a+b+c=a*b*c, and
  // replace with a/100, b/100, c/100 since a, b, and c are integers here
  // instead of numbers with two decimal points)
  //
  // c = 10000 * (a + b) / (a * b - 10000) (derived from above equation by
  // isolating c)
  //
  // The basic premise is that we can eliminate the deepest for loop by solving
  // for c. If c the numerator and denominator of the equation above divide
  // perfectly, c will be an integer and is accepted.
  for (int a = 1; a <= 25600; ++a) {
    // Starting b here allows us to avoid dealing with cases where den is 0
    // or negative.
    // But note that b must also be kept >= a to avoid repeats
    for (int b = a > 10000 / a + 1 ? a : 10000 / a + 1; b <= 25600 - a; ++b) {
      ll num = 10000 * (a + b);
      ll den = a * b - 10000;
      int c = num / den;
      // Avoid repeats by ensuring c is >= b
      if (num % den == 0 && c >= b) {
        int reg_sum = a + b + c;
        if (reg_sum > 25600) continue;  // avoid overly large sums
        sums[reg_sum].push_back({a, b, c});
      }
    }
  }

  // Search for appropriate values
  for (int i = lo; i <= hi; ++i) {
    for (unsigned int j = 0; j < sums[i].size(); ++j) {
      float a = (float)sums[i][j][0] / 100;
      float b = (float)sums[i][j][1] / 100;
      float c = (float)sums[i][j][2] / 100;
      printf("%.2f = %.2f + %.2f + %.2f = %.2f * %.2f * %.2f\n", (float)i / 100,
             a, b, c, a, b, c);
    }
  }

  return 0;
}
