// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10919
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
  int k, m;
  int c, r;
  int tmp;
  bool satisfied;
  set<int> courses;
  while (GET(k) && k != 0) {
    GET(m);
    courses.clear();
    FOR(i, 0, k) {
      GET(tmp);
      courses.insert(tmp);
    }

    satisfied = true;
    FOR(i, 0, m) {
      GET(c);
      GET(r);
      int met = 0;
      FOR(j, 0, c) {
        GET(tmp);
        if (courses.find(tmp) != courses.end()) ++met;
      }
      satisfied &= met >= r;
    }

    if (satisfied) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
  return 0;
}
