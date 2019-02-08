// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 154
#include <bits/stdc++.h>
using namespace std;

// r, o, y, g, b
char allocs[110][5];

int bin_to_int(char bin) {
  switch (bin) {
    case 'r':
      return 0;
    case 'o':
      return 1;
    case 'y':
      return 2;
    case 'g':
      return 3;
    case 'b':
      return 4;
    default:
      return -1;
  }
}

int main() {
  // Possible edge case: 0 allocations?
  char buf[40];
  int cities = 0;
  while (scanf("%s", buf)) {
    // Get input
    if (buf[0] != 'e' && buf[0] != '#') {
      for (int i = 0; i < 5; ++i) {
        allocs[cities][bin_to_int(buf[i * 4])] = buf[2 + i * 4];
      }
      ++cities;
    }

    // Dump output
    if (buf[0] == 'e') {
      int best_match = 1000000000;
      int best_city = 0;
      for (int i = 0; i < cities; ++i) {
        // Count the number of changes that would be needed if this city was
        // chosen.
        int changes = 0;
        for (int j = 0; j < cities; ++j) {
          for (int k = 0; k < 5; ++k) {
            if (allocs[i][k] != allocs[j][k]) ++changes;
          }
        }
        if (changes < best_match) {
          best_city = i + 1;
          best_match = changes;
        }
      }
      cities = 0;
      printf("%d\n", best_city);
    }

    // End
    if (buf[0] == '#') break;
  }
  return 0;
}
