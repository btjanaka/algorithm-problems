// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 297
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

bool pic[32][32];

void fill(const string& s, int& ind, int r0, int c0, int dim) {
  if (s[ind] == 'p') {
    ++ind;
    fill(s, ind, r0, c0 + dim / 2, dim / 2);
    fill(s, ind, r0, c0, dim / 2);
    fill(s, ind, r0 + dim / 2, c0, dim / 2);
    fill(s, ind, r0 + dim / 2, c0 + dim / 2, dim / 2);
  } else if (s[ind] == 'e') {
    ++ind;
  } else if (s[ind] == 'f') {
    ++ind;
    for (int i = 0; i < dim; ++i) {
      for (int j = 0; j < dim; ++j) {
        pic[r0 + i][c0 + j] = true;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int ca;
  cin >> ca;
  string a, b;
  while (ca--) {
    memset(pic, 0, sizeof(pic));
    cin >> a >> b;

    int ind = 0;
    fill(a, ind, 0, 0, 32);
    ind = 0;
    fill(b, ind, 0, 0, 32);

    int res = 0;
    for (int i = 0; i < 32; ++i)
      for (int j = 0; j < 32; ++j) res += pic[i][j];

    printf("There are %d black pixels.\n", res);
  }
  return 0;
}
