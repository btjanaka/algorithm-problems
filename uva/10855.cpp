// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10855
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
#define SZ 5000

int b, s;
char big[SZ][SZ];
char small[SZ][SZ];
char small2[SZ][SZ];

void rotate() {
  for (int i = 0; i < s; ++i)
    for (int j = 0; j < s; ++j) small2[j][s - i - 1] = small[i][j];

  for (int i = 0; i < s; ++i)
    for (int j = 0; j < s; ++j) small[i][j] = small2[i][j];
}

int count_match() {
  int matched = 0;
  for (int i = 0; i <= b - s; ++i) {
    for (int j = 0; j <= b - s; ++j) {
      bool ok = true;
      for (int r = 0; r < s; ++r) {
        for (int c = 0; c < s; ++c) {
          ok &= small[r][c] == big[r + i][c + j];
        }
      }
      if (ok) ++matched;
    }
  }
  return matched;
}

int main() {
  while (GET(b) && GET(s) && !(!b && !s)) {
    for (int i = 0; i < b; ++i) scanf("%s", big[i]);
    for (int i = 0; i < s; ++i) scanf("%s", small[i]);

    for (int i = 0; i < 4; ++i) {
      printf("%d%c", count_match(), i == 3 ? '\n' : ' ');
      rotate();
    }
  }
  return 0;
}
