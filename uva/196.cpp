// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 196
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct data {
  int val;
  bool has_val;
  vector<ii> deps;
  data() : val(0), has_val(false), deps(0) {}
  void clear() {
    val = false;
    has_val = false;
    deps.clear();
  }
};

int col, row;
data sheet[1010][20000];
data f(int r, int c) {
  if (sheet[r][c].has_val) return sheet[r][c];

  for (int i = 0; i < sheet[r][c].deps.size(); ++i) {
    sheet[r][c].val +=
        f(sheet[r][c].deps[i].first, sheet[r][c].deps[i].second).val;
  }
  sheet[r][c].has_val = true;

  return sheet[r][c];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ca;
  cin >> ca;
  string line;
  string cell;

  while (ca--) {
    // input
    cin >> col >> row;
    getline(cin, line);
    for (int i = 0; i < row; ++i) {
      getline(cin, line);
      stringstream cells(line);
      for (int j = 0; cells >> cell; ++j) {
        sheet[i][j].clear();
        if (cell[0] == '=') {
          sheet[i][j].has_val = false;
          int c = 0, r = 0;
          for (int k = 1; k < cell.size(); ++k) {
            if (isalpha(cell[k])) {
              c = 26 * c + cell[k] - 'A' + 1;
            } else if (isdigit(cell[k])) {
              r = 10 * r + cell[k] - '0';
            } else if (cell[k] == '+') {
              sheet[i][j].deps.push_back({r - 1, c - 1});
              r = c = 0;
            }
          }
          sheet[i][j].deps.push_back({r - 1, c - 1});
        } else {
          sheet[i][j].has_val = true;
          sheet[i][j].val = atoi(cell.c_str());
        }
      }
    }

    // fill up table
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        sheet[i][j] = f(i, j);
      }
    }

    // output
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        printf("%d%c", sheet[i][j].val, j == col - 1 ? '\n' : ' ');
      }
    }
  }
  return 0;
}
