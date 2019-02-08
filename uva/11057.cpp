// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11057
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

int books[11000];

int main() {
  // Sort input and then binary search for corresponding value for each price in
  // the array.
  int n;
  int m;
  while (GET(n) > 0) {
    FOR(i, 0, n) GET(books[i]);
    sort(books, books + n);
    GET(m);
    int i_f = 0;
    int j_f = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int price_i = books[i];
      int price_j = m - price_i;
      int* found;
      if (price_i <= price_j && price_j - price_i <= j_f - i_f) {
        // Pay attention: lower_bound only returns the first entry in the array
        // that is >= the value; it does not necessarily return the value.
        if ((found = lower_bound(books + i + 1, books + n, price_j)) !=
                books + n &&
            *found == price_j) {
          i_f = price_i;
          j_f = price_j;
        }
      }
    }
    printf("Peter should buy books whose prices are %d and %d.\n\n", i_f, j_f);
  }
  return 0;
}
