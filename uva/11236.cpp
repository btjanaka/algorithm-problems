// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11236
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
#define GET(x) \
  int x;       \
  scanf("%d", &x);
typedef long long ll;
using namespace std;

// a,b,c,d all represent number of cents. Recognize that:
// * a/100 + b/100 + c/100 + d/100 = a/100 * b/100 * c/100 * d/100
// * d = (10^6 * (a+b+c)) / (a*b*c - 10^6)
// * a + b + c + d <= 2000
int main() {
  ll sum, prod, d;
  for (ll a = 1; a <= 2000; ++a) {
    for (ll b = a; b <= 2000 - a; ++b) {
      for (ll c = b; c <= 2000 - a - b; ++c) {
        sum = (a + b + c) * 1000000;
        prod = a * b * c - 1000000;
        if (prod > 0 && sum % prod == 0) {
          d = sum / prod;
          if (a + b + c + d <= 2000 && d >= c) {
            printf("%.2lf %.2lf %.2lf %.2lf\n", (double)a / 100,
                   (double)b / 100, (double)c / 100, (double)d / 100);
          }
        }
      }
    }
  }
  return 0;
}
