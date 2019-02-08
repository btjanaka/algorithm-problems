// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12554
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
  int n;
  GET(n);
  getchar();
  char names[110][110];
  FOR(i, 0, n) {
    fgets(names[i], 110, stdin);
    *strrchr(names[i], '\n') = 0;
  }
  int name_i = 0;
  for (int i = 1;; ++i) {
    printf("%s: ", names[name_i++]);
    name_i %= n;
    if ((i - 12) % 16 == 0) {
      printf("Rujia");
    } else if (i % 4 == 0) {
      printf("you");
    } else if ((i - 3) % 4 == 0) {
      printf("to");
    } else if ((i - 2) % 4 == 0) {
      printf("birthday");
    } else if ((i - 1) % 4 == 0) {
      printf("Happy");
    }
    PLN;
    if (i % 16 == 0 && i >= n) break;
  }
  return 0;
}
