// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10102
#include <bits/stdc++.h>
using namespace std;

char field[200][200];

int main() {
  int m;
  while (scanf("%d", &m) > 0) {
    // Input
    for (int i = 0; i < m; ++i) {
      scanf("%s", field[i]);
    }

    // Go through the entire grid looking for 1's (initial states); for each
    // one, look for the nearest 3. The maximum of these distances is the
    // minimum distance needed to get to a 3 from an initial state.
    int max_min_d = -1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        if (field[i][j] == '1') {
          bool found_three = false;
          for (int x = 0; x < m && !found_three; ++x) {
            for (int y = 0; y < m && !found_three; ++y) {
              if ((i + x < m && j + y < m && field[i + x][j + y] == '3') ||
                  (i - x >= 0 && j - y >= 0 && field[i - x][j - y] == '3')) {
                max_min_d = max(max_min_d, x + y);
                found_three = true;
              }
            }
          }
        }
      }
    }

    // Output
    printf("%d\n", max_min_d);
  }
  return 0;
}
