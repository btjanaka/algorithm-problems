// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) oddgnome
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
typedef long long ll;
using namespace std;

int main() {
  int n;
  GET(n);
  FOR(i, 0, n) {
    int g;
    GET(g);
    int cur, prev;
    bool found = false;
    FOR(i, 0, g) {
      GET(cur);
      if (g == 3 && i == 1) {
        cout << i + 1 << endl;
        found = true;
      }
      if (!found && i >= 1 && i != g - 1) {
        if (cur != prev + 1) {
          cout << i + 1 << endl;
          found = true;
        }
      }
      prev = cur;
    }
  }
  return 0;
}
