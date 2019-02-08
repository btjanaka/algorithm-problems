// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10324
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

// Each index holds the sum of all the numbers in the original bit string up to
// and including that index.
int cum_sum[1001000];

int main() {
  for (int cas = 1;; ++cas) {
    // Get string
    int len = 0;
    char ch;
    while ((ch = getchar()) != EOF && ch != '\n') {
      if (len == 0) {
        cum_sum[len++] = ch - '0';
      } else {
        cum_sum[len] = ch - '0' + cum_sum[len - 1];
        ++len;
      }
    }
    if (len == 0) break;

    // Process queries
    printf("Case %d:\n", cas);
    int n;
    GET(n);
    int i, j, t1, t2;
    FOR(k, 0, n) {
      scanf("%d %d", &t1, &t2);
      i = min(t1, t2);
      j = max(t1, t2);
      int lo_sum = i == 0 ? 0 : cum_sum[i - 1];
      int hi_sum = cum_sum[j];
      if (hi_sum - lo_sum == 0 || hi_sum - lo_sum == j - i + 1) {
        printf("Yes\n");
      } else {
        printf("No\n");
      }
    }
    getchar();  // Stray newline
  }
  return 0;
}
