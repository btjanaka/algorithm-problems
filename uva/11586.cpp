// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11586
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
  int t;
  GET(t);
  getchar();
  char ch;
  while (t--) {
    int tot = 0;
    int num_pieces = 0;  // keep track because 1 piece is not enough
    while ((ch = getchar()) != EOF && ch != '\n') {
      if (ch == 'M') {
        ++tot;
        ++num_pieces;
      } else if (ch == 'F') {
        --tot;
        ++num_pieces;
      }
    }
    num_pieces /= 2;
    if (tot == 0 && num_pieces > 1) {
      printf("LOOP\n");
    } else {
      printf("NO LOOP\n");
    }
  }
  return 0;
}
