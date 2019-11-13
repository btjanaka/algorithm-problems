// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) connectthedots
// Title: Connect the Dots
// Link: https://open.kattis.com/problems/connectthedots
// Idea: Find all the dots and connect them. Maintain the whole grid and modify
// it as appropriate.
// Difficulty: medium
// Tags: implementation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
typedef long long ll;
using namespace std;

char grid[110][110];
char dots[62] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
                 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w',
                 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main() {
  char buf[110];
  bool first = true;
  while (fgets(buf, 110, stdin)) {
    // Coordinates of each dot - row, column
    unordered_map<char, pair<int, int>> coord;

    // Input the grid while recording the coordinates of dots to connect.
    int width = strlen(buf) - 1;
    int height = 0;
    do {
      for (int i = 0; i < width; ++i) {
        grid[height][i] = buf[i];
        if (buf[i] != '.') {
          coord[buf[i]] = make_pair(height, i);
        }
      }
      ++height;
    } while (fgets(buf, 110, stdin) && buf[0] != '\n');

    // Keep finding next dot and connecting it to previous dot.
    for (int i = 0; coord.find(dots[i]) != coord.end(); ++i) {
      char dot = dots[i];

      if (i != 0) {
        char prev = dots[i - 1];
        if (coord[prev].first == coord[dot].first) {
          // Same row
          int row = coord[prev].first;
          int col1 = min(coord[prev].second, coord[dot].second);
          int col2 = max(coord[prev].second, coord[dot].second);
          for (int c = col1 + 1; c < col2; ++c) {
            if (grid[row][c] == '.') {
              grid[row][c] = '-';
            } else if (grid[row][c] == '|') {
              grid[row][c] = '+';
            }
          }
        } else if (coord[prev].second == coord[dot].second) {
          // Same column
          int col = coord[prev].second;
          int row1 = min(coord[prev].first, coord[dot].first);
          int row2 = max(coord[prev].first, coord[dot].first);
          for (int r = row1 + 1; r < row2; ++r) {
            if (grid[r][col] == '.') {
              grid[r][col] = '|';
            } else if (grid[r][col] == '-') {
              grid[r][col] = '+';
            }
          }
        }
      }
    }

    // Output
    if (first) {
      first = false;
    } else {
      printf("\n");
    }
    for (int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        putchar(grid[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
