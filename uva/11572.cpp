// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11572
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n;
    GET(n);
    // snowflake, last position it was seen at
    unordered_map<int, int> last_pos;
    int begin = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      GET(x);
      if (last_pos.find(x) != last_pos.end() && last_pos[x] >= begin) {
        mx = max(mx, i - begin);
        begin = last_pos[x] + 1;
      }
      last_pos[x] = i;
    }
    mx = max(mx, n - begin);
    printf("%d\n", mx);
  }
  return 0;
}
