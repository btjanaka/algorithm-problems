// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) game-with-cells
// Title: Army Game
// Link: https://www.hackerrank.com/challenges/game-with-cells/problem
// Idea: See the grid as composed of larger 2x2 cells, as one package can cover
// each 2x2 grid by being dropped in their shared corner.
// Difficulty: easy
// Tags: math, geometry
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  n = n / 2 + n % 2;
  m = m / 2 + m % 2;
  cout << n * m << endl;
  return 0;
}
