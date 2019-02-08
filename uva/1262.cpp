// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 1262
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

// Returns a bool telling if the k'th element could be found.
// Goes through all possible passwords in grid1 in lexicographical order, but
// only considers characters if they are also in grid2 (which is why the set is
// necessary). Generates passwords until *cur_k == k. *cur_k tracks how many
// passwords have been generated so far.
bool backtrack(char pwd[], int col, int* cur_k, int k, char grid1[5][6],
               set<int> grid2[5]) {
  // End case: have enough characters to make a password
  if (col == 5) {
    if (*cur_k == k) {
      return true;
    } else {
      (*cur_k)++;
      return false;
    }
  }

  // Go through characters in this column of grid1, but make sure to leave out
  // repeated characters, so we don't generate repeated passwords.
  for (int i = 0; i < 6; ++i) {
    if (i == 0 || grid1[col][i] != grid1[col][i - 1]) {
      if (grid2[col].find(grid1[col][i]) != grid2[col].end()) {
        pwd[col] = grid1[col][i];
        if (backtrack(pwd, col + 1, cur_k, k, grid1, grid2)) return true;
      }
    }
  }

  return false;
}

int main() {
  // Stored as columns that each keep track of rows
  char grid1[5][6];
  set<int> grid2[5];

  char buf[10];

  int t;
  GET(t);

  while (t--) {
    // Reset
    for (int i = 0; i < 5; ++i) grid2[i].clear();

    // Input
    int k;
    GET(k);
    // Grid 1
    for (int i = 0; i < 6; ++i) {
      scanf("%s", buf);
      for (int j = 0; j < 5; ++j) {
        grid1[j][i] = buf[j];
      }
    }
    // Sort grid1's columns
    for (int i = 0; i < 5; ++i) {
      sort(grid1[i], grid1[i] + 6);
    }
    // Grid 2
    for (int i = 0; i < 6; ++i) {
      scanf("%s", buf);
      for (int j = 0; j < 5; ++j) {
        grid2[j].insert(buf[j]);
      }
    }

    // Output
    char pwd[6];
    memset(pwd, 0, sizeof(pwd));
    int cur_k = 1;
    if (backtrack(pwd, 0, &cur_k, k, grid1, grid2)) {
      printf("%s\n", pwd);
    } else {
      printf("NO\n");
    }
  }
  return 0;
}
