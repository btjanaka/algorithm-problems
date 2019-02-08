// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12503
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
  char buf[100];
  char moves[110];
  while (t--) {
    int n;
    GET(n);
    getchar();  // stray newline
    int p = 0;
    for (int i = 1; i <= n; ++i) {
      fgets(buf, 100, stdin);
      *strrchr(buf, '\n') = 0;
      if (strcmp(buf, "LEFT") == 0) {
        moves[i] = 'L';
        --p;
      } else if (strcmp(buf, "RIGHT") == 0) {
        moves[i] = 'R';
        ++p;
      } else {
        int same_i = atoi(buf + 8);
        moves[i] = moves[same_i];
        if (moves[i] == 'L') {
          --p;
        } else {
          ++p;
        }
      }
    }
    printf("%d\n", p);
  }
  return 0;
}
