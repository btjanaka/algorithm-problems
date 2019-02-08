// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10611
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

int ladies[55000];

int main() {
  int n;
  int q;
  GET(n);
  FOR(i, 0, n) GET(ladies[i]);
  GET(q);
  FOR(i, 0, q) {
    int qu;
    GET(qu);

    // Find the tallest lady shorter than Luchu.
    int *lower = lower_bound(ladies, ladies + n, qu);
    // 3 outcomes:
    // * qu is not found, in which case the last element can be used
    // * qu is found and is somewhere in the middle of the array, so we can use
    //   the element before it (this combines with the previous case)
    // * qu is found, but it is the first element of the array - in this case,
    //   there is no proper element, so we print X
    if (lower == ladies) {
      printf("X ");
    } else {
      printf("%d ", *(lower - 1));
    }

    // Find the shortest lady taller than Luchu
    int *upper = upper_bound(ladies, ladies + n, qu);
    if (upper == ladies + n) {
      printf("X\n");
    } else {
      printf("%d\n", *upper);
    }
  }
  return 0;
}
