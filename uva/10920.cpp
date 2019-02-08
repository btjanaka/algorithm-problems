// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10920
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

ll find_root(ll n) {
  ll lo = 0, hi = 100000;
  while (true) {
    ll mid = ll(lo + hi) / 2;
    ll sq = mid * mid;
    if (sq == n)
      return mid;
    else if (sq < n)
      lo = mid + 1;
    else
      hi = mid;
    if (hi == lo) return lo;
  }
}

int main() {
  int sz;
  ll p;
  while (GET(sz) && scanf("%lld", &p) && !(!sz && !p)) {
    // find previous square and calc distance to it
    ll center = sz / 2 + 1;
    ll prev_sqrt = find_root(p);
    if (prev_sqrt * prev_sqrt > p) prev_sqrt--;
    if (!(prev_sqrt & 1L)) prev_sqrt--;
    ll prev_sq = prev_sqrt * prev_sqrt;
    ll prev_sq_x = (prev_sqrt - 1) / 2 + center;
    ll prev_sq_y = prev_sq_x;

    // go through individual branches of spiral
    ll x = prev_sq_x, y = prev_sq_y;
    ll d = prev_sqrt + 1;
    ll last_pos = prev_sq;
    // printf("%lld %lld %lld\n", last_pos, x, y);
    if (p > last_pos) {
      y += 1LL;
      x = max(x - d + 1, x - (p - last_pos - 1L));
    }
    last_pos += d;
    // printf("%lld %lld %lld\n", last_pos, x, y);
    if (p >= last_pos) {
      y = max(y - d, y - (p - last_pos));
    }
    last_pos += d;
    // printf("%lld %lld %lld\n", last_pos, x, y);
    if (p >= last_pos) {
      x = min(x + d, x + (p - last_pos));
    }
    last_pos += d;
    // printf("%lld %lld %lld\n", last_pos, x, y);
    if (p >= last_pos) {
      y = y + (p - last_pos);  // should not exceed
    }

    printf("Line = %lld, column = %lld.\n", y, x);
  }
  return 0;
}
