// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11687
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

int count_digits(int num) {
  if (num == 0) return 1;
  int digits = 0;
  for (; num > 0; num /= 10) {
    ++digits;
  }
  return digits;
}

char buf[1001000];

int main() {
  while (scanf("%s", buf) && strcmp(buf, "END") != 0) {
    int x = strlen(buf);
    char len[15];
    sprintf(len, "%d", x);

    // Check if i can be 1
    if (strcmp(len, buf) == 0) {
      printf("1\n");
    } else {
      int next_x = count_digits(x);
      int i = 2;
      while (next_x != x) {
        x = next_x;
        next_x = count_digits(x);
        ++i;
      }
      printf("%d\n", i);
    }
  }
  return 0;
}
