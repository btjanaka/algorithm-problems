// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 679
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
  int l;
  GET(l);
  int d, i;
  while (l--) {
    scanf("%d %d", &d, &i);

    // Since each node toggles, we can know which way to go by looking at how
    // many balls have gone past each point.
    int max_node = 1 << d;
    int curr = 1;
    int left = 2;
    int right = 3;
    while (left < max_node) {
      if (i % 2 == 1) {
        curr = left;
        i = i / 2 + 1;
      } else {
        curr = right;
        i = i / 2;
      }
      left = 2 * curr;
      right = 2 * curr + 1;
    }
    printf("%d\n", curr);
  }
  return 0;
}
