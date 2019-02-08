// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11942
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
  printf("Lumberjacks:\n");
  while (n--) {
    int prev;
    int curr;
    bool order_type;  // true for increasing, false for decreasing
    bool ordered = true;
    for (int i = 0; i < 10; ++i) {
      GET(curr);
      switch (i) {
        case 0:
          break;
        case 1:
          // Determine order - note that the integers are distinct
          order_type = prev < curr;
        default:
          if (order_type) {
            ordered &= prev < curr;
          } else {
            ordered &= prev > curr;
          }
      }
      prev = curr;
    }
    printf(ordered ? "Ordered\n" : "Unordered\n");
  }
  return 0;
}
