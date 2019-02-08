// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10189
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int m, n;
  char field[110][110];
  int mines[110][110];
  bool first = true;
  for (int ca = 1; scanf("%d %d", &m, &n) && m && n; ++ca) {
    getchar();
    for (int i = 0; i < m; ++i) {
      fgets(field[i], 110, stdin);
      field[i][n] = 0;
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (field[i][j] == '.') {
          mines[i][j] = 0;
          mines[i][j] += i > 0 && field[i - 1][j] == '*';
          mines[i][j] += i < m - 1 && field[i + 1][j] == '*';
          mines[i][j] += j > 0 && field[i][j - 1] == '*';
          mines[i][j] += j < n - 1 && field[i][j + 1] == '*';
          mines[i][j] += i > 0 && j > 0 && field[i - 1][j - 1] == '*';
          mines[i][j] += i > 0 && j < n - 1 && field[i - 1][j + 1] == '*';
          mines[i][j] += i < m - 1 && j > 0 && field[i + 1][j - 1] == '*';
          mines[i][j] += i < m - 1 && j < n - 1 && field[i + 1][j + 1] == '*';
        } else {
          mines[i][j] = -1;
        }
      }
    }

    if (first)
      first = false;
    else
      printf("\n");
    printf("Field #%d:\n", ca);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mines[i][j] == -1) {
          printf("*");
        } else {
          printf("%d", mines[i][j]);
        }
      }
      printf("\n");
    }
  }
  return 0;
}
