// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11661
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

int restaurants[2000000];
int drugstores[2000000];
int num_r;
int num_d;

int main() {
  int l;
  while (GET(l) && l != 0) {
    getchar();  // clear newline
    char ch;
    int pos = 0;
    num_r = 0;
    num_d = 0;
    int min_d = INF;
    while ((ch = getchar()) && ch != '\n') {
      if (ch == 'Z') {
        restaurants[num_r++] = pos;
        drugstores[num_d++] = pos;
        min_d = 0;
      } else if (ch == 'R') {
        restaurants[num_r++] = pos;
      } else if (ch == 'D') {
        drugstores[num_d++] = pos;
      }
      ++pos;
    }

    if (min_d == 0) {
      printf("0\n");
    } else {
      for (int r = 0; r < num_r; ++r) {
        for (int d = 0; d < num_d; ++d) {
          int dist = abs(drugstores[d] - restaurants[r]);
          if (dist < min_d) min_d = dist;
          if (min_d == 1) goto gotmin;
        }
      }
    gotmin:
      printf("%d\n", min_d);
    }
  }
  return 0;
}
