// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10037
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

int ppl[1010];
pair<int, int> data[10000];

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n;
    GET(n);
    FOR(i, 0, n) { GET(ppl[i]); }
    sort(ppl, ppl + n);

    // See
    // https://codingstrife.wordpress.com/2013/07/23/solution-uva10037-pc110403-bridge/
    // for algorithm
    int tot = 0;
    int d_i = 0;

    // Move all the slowest members over
    // In each case, ppl[0] and ppl[1] start on the uncrossed side. ppl[i] and
    // ppl[i + 1] are the slow members that need to cross.
    // Method 1: fastest person does all the moving
    // Method 2: fastest and next fastest work together
    int limit = (n % 2 == 0) ? 2 : 3;
    for (int i = n - 2; i >= limit; i -= 2) {
      int method1 = ppl[i] + ppl[0] + ppl[i + 1] + ppl[0];
      int method2 = ppl[1] + ppl[0] + ppl[i + 1] + ppl[1];
      if (method1 < method2) {
        tot += method1;
        data[d_i++] = make_pair(ppl[0], ppl[i]);
        data[d_i++] = make_pair(ppl[0], -1);
        data[d_i++] = make_pair(ppl[0], ppl[i + 1]);
        data[d_i++] = make_pair(ppl[0], -1);
      } else {
        tot += method2;
        data[d_i++] = make_pair(ppl[0], ppl[1]);
        data[d_i++] = make_pair(ppl[0], -1);
        data[d_i++] = make_pair(ppl[i], ppl[i + 1]);
        data[d_i++] = make_pair(ppl[1], -1);
      }
      n -= 2;
    }

    // There should now be 1, 2, or 3 members left, and they should all be the
    // fastest of the original group. There is only one optimal crossing for
    // each of these cases.
    switch (n) {
      case 1:
        data[d_i++] = make_pair(ppl[0], -1);
        tot += ppl[0];
        break;
      case 2:
        data[d_i++] = make_pair(ppl[0], ppl[1]);
        tot += ppl[1];
        break;
      case 3:
        data[d_i++] = make_pair(ppl[0], ppl[1]);
        data[d_i++] = make_pair(ppl[0], -1);
        data[d_i++] = make_pair(ppl[0], ppl[2]);
        tot += ppl[2] + ppl[0] + ppl[1];
        break;
    }

    // Output
    printf("%d\n", tot);
    FOR(i, 0, d_i) {
      printf("%d", data[i].first);
      if (data[i].second != -1) printf(" %d", data[i].second);
      PLN;
    }

    if (ca) PLN;
  }
  return 0;
}
