// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11926
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

void check_interval(int b, int e, bitset<1000001>& begin, bitset<1000001>& end,
                    bool& ok) {
  if (begin[b]) ok = false;
  if (end[e]) ok = false;
  begin[b] = true;
  end[e] = true;

  for (int i = b + 1; i <= e - 1; ++i) {
    if (begin[i] || end[i]) {
      ok = false;
      break;
    }
    begin[i] = true;
    end[i] = true;
  }
}

int main() {
  int n, m;
  while (GET(n) && GET(m) && !(!n && !m)) {
    bitset<1000001> begin;
    bitset<1000001> end;
    int b, e, r;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      GET(b);
      GET(e);
      if (ok) {
        check_interval(b, e, begin, end, ok);
      }
    }
    for (int i = 0; i < m; ++i) {
      GET(b);
      GET(e);
      GET(r);
      if (ok) {
        if (r < e - b) ok = false;
        while (ok && e <= 1000000) {
          check_interval(b, e, begin, end, ok);
          b += r;
          e += r;
        }
      }
    }

    printf("%s\n", ok ? "NO CONFLICT" : "CONFLICT");
  }
  return 0;
}
