// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 750
#include <bits/stdc++.h>
using namespace std;

int queens[8];             // Store the row of each queen
int special_r, special_c;  // For the one queen that has a set position
int lineno;

bool place(int r, int c) {
  for (int i = 0; i < c; ++i)
    // Check if the queen can be placed at this row and column by looking at
    // all the other columns and checking if the queens there are on the
    // same row or are diagonally away.
    if (queens[i] == r || abs(queens[i] - r) == abs(i - c)) return false;
  return true;
}

// Backtracking = incrementally building candidate solutions to a problem, and
// then abandoning the solution (i.e. backtracking) when we realize that it
// cannot be valid
//
// In this case, we are building up solutions by placing queens in subsequent
// columns. When we realize that a queen cannot go in a certain row and column,
// we no longer build that solution. This ability to fit in a certain row and
// column is determined by the place function. If the queen does fit, we
// continue to build it by adding another queen. Eventually, we reach 8 queens
// and print a solution.
void backtrack(int c) {  // c is the column that we are currently investigating
  if (c == 8) {          // Found a solution, so print it
    printf("%2d      %d", ++lineno, queens[0] + 1);
    for (int i = 1; i < 8; ++i) printf(" %d", queens[i] + 1);
    putchar('\n');
  }
  for (int r = 0; r < 8; r++) {  // Try every possible row for this column
    if (((c == special_c && r == special_r) || c != special_c) && place(r, c)) {
      queens[c] = r;
      backtrack(c + 1);
    }
  }
}

int main() {
  int t;
  scanf("%d\n", &t);
  while (t--) {
    scanf("%d %d\n", &special_r, &special_c);
    --special_r;
    --special_c;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    memset(queens, 0, sizeof queens);
    lineno = 0;
    backtrack(0);
    if (t) putchar('\n');
  }
  return 0;
}
