// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11157
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

int stones[110];
char sizes[110];  // 'B' for big, 'S' for small, 'X' for used

int main() {
  int t;
  GET(t);
  FORe(ca, 1, t) {
    // Get input - add beginning and end points to stones
    int n, d;
    GET(n);
    GET(d);
    n += 2;  // For beginning and end
    stones[0] = 0;
    sizes[0] = 'B';
    FOR(i, 1, n - 1) { scanf(" %c%*c%d", &sizes[i], &stones[i]); }
    stones[n - 1] = d;
    sizes[n - 1] = 'B';

    // Debug
    // FOR(i, 0, n) { printf("%3d", stones[i]); }
    // PLN;
    // FOR(i, 0, n) { printf("%3c", sizes[i]); }
    // PLN;

    // Go through the stones, searching for big ones. Between this big one and
    // the next big one, find out the maximum distance the frog will have to
    // jump. This maximum distance is found by first going through every other
    // stone to get from one big stone to the next, then going back through the
    // other half of the stones to get back. The maximum is the maximum of any
    // of these distances.
    //
    // The key realization here is that the frog has to use all the stones to
    // minimize distance. Furthermore, the frog has to use all the big stones
    // going both ways. It also has to use half the small stones going one way,
    // and half going back the other way.

    int b1 = 0;
    int b2 = 0;
    int mx = 0;
    while (b1 != n - 1) {
      // Find next big one
      for (b2 = b1 + 1; sizes[b2] != 'B'; ++b2)
        ;
      // Going across one way
      for (int i = b1; i < b2; i += 2) {
        if (i == b2 - 1) {
          mx = max(mx, stones[i + 1] - stones[i]);
        } else {
          mx = max(mx, stones[i + 2] - stones[i]);
        }
      }
      // Going across with the other set of stones
      mx = max(mx, stones[b1 + 1] - stones[b1]);
      for (int i = b1 + 1; i < b2; i += 2) {
        if (i == b2 - 1) {
          mx = max(mx, stones[i + 1] - stones[i]);
        } else {
          mx = max(mx, stones[i + 2] - stones[i]);
        }
      }
      // Advance big stones
      b1 = b2;
    }

    // Output
    printf("Case %d: %d\n", ca, mx);
  }
  return 0;
}
