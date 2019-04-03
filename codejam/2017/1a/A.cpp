// Author: btjanaka (Bryon Tjanaka)
// Problem: (Google Code Jam) Alphabet Cake
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ca;
  cin >> ca;
  for (int caa = 1; caa <= ca; ++caa) {
    int r, c;
    cin >> r >> c;
    cin.get();
    vector<string> grid(r);
    for (int i = 0; i < r; ++i) getline(cin, grid[i]);

    // Fill up rows by expanding horizontally
    for (int i = 0; i < r; ++i) {
      int first_index = -1;
      char cur;
      for (int j = 0; j < c; ++j) {
        if (first_index != -1 && grid[i][j] == '?') {
          grid[i][j] = cur;
        } else if (grid[i][j] != '?' && first_index == -1) {
          first_index = j;
          cur = grid[i][j];
        } else {
          cur = grid[i][j];
        }
      }
      if (first_index != -1) {
        cur = grid[i][first_index];
        for (int j = first_index; j >= 0; --j) {
          grid[i][j] = cur;
        }
      }
    }

    // Check for empty horizontal rows and copy the one above if they are
    int first_nonempty = -1;
    int cur_row = -1;
    for (int i = 0; i < r; ++i) {
      if (grid[i][0] != '?' && first_nonempty == -1) {
        first_nonempty = i;
        cur_row = i;
      } else if (grid[i][0] != '?') {
        cur_row = i;
      } else if (grid[i][0] == '?' && first_nonempty != -1) {
        grid[i] = grid[cur_row];
      }
    }
    for (int i = first_nonempty; i >= 0; --i) {
      grid[i] = grid[first_nonempty];
    }

    printf("Case #%d:\n", caa);
    for (int i = 0; i < r; ++i) {
      printf("%s\n", grid[i].c_str());
    }
  }
  return 0;
}
