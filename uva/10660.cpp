// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10660
#include <bits/stdc++.h>
using namespace std;

int n;

// row, column, population
int pops[25][3];

// Temp for storing cities
int cities[5];

// Map a row and column to each number on the board (easier to access later on)
int rows[25];
int cols[25];

void populate_rc() {
  for (int i = 0; i < 25; ++i) {
    rows[i] = i / 5;
    cols[i] = i % 5;
  }
}

// Find the minimum distance from each population to an office
long long calc_d() {
  long long tot_d = 0;
  for (int p = 0; p < n; ++p) {
    int min_to_office = 1000000000;
    for (int i = 0; i < 5; ++i) {
      min_to_office = min(min_to_office, (abs(pops[p][0] - rows[cities[i]]) +
                                      abs(pops[p][1] - cols[cities[i]])));
    }
    tot_d += min_to_office * pops[p][2];
  }
  return tot_d;
}

int main() {
  populate_rc();
  int t;
  scanf("%d", &t);
  while (t--) {
    // Input
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d %d %d", &pops[i][0], &pops[i][1], &pops[i][2]);
    }

    // Go through all possible combos of cities; for each combo find minimum
    // distance from each population to office.
    int res[5];
    long long min_d = 2000000000000000L;
    for (cities[0] = 0; cities[0] < 25; ++cities[0]) {
      for (cities[1] = cities[0] + 1; cities[1] < 25; ++cities[1]) {
        for (cities[2] = cities[1] + 1; cities[2] < 25; ++cities[2]) {
          for (cities[3] = cities[2] + 1; cities[3] < 25; ++cities[3]) {
            for (cities[4] = cities[3] + 1; cities[4] < 25; ++cities[4]) {
              long long temp_d = calc_d();
              if (temp_d < min_d) {
                min_d = temp_d;
                memcpy(res, cities, 5 * sizeof(int));
              }
            }
          }
        }
      }
    }

    // Output
    printf("%d", res[0]);
    for (int i = 1; i <= 4; ++i) {
      printf(" %d", res[i]);
    }
    putchar('\n');
  }
  return 0;
}
