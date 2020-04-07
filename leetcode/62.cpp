// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 62
// Link: https://leetcode.com/problems/unique-paths/
// Idea: We know the robot can move only down and right. At each square, the
// number of ways to get to the goal may be represented as the sum of:
// 1) the number of ways to reach the goal from the square below us (i.e. how
//    many ways we can go if we go down)
// 2) the number of ways to reach the goal from the square to the right of us
//   (i.e. how many ways we can go if we go right)
// If there is no square below or to the right of us, the corresponding amount
// is left out. And at the goal itself, there is only 1 way to reach the goal,
// of course.
// Difficulty: medium
// Tags: dynamic-programming
class Solution {
 public:
  int uniquePaths(int m, int n) {
    int paths[m][n];
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (i == m - 1 && j == n - 1) {
          // 1 way at the goal
          paths[i][j] = 1;
        } else {
          // Otherwise...
          paths[i][j] = 0;
          // Add paths from the square below
          if (i < m - 1) paths[i][j] += paths[i + 1][j];
          // Add paths from the square to the right
          if (j < n - 1) paths[i][j] += paths[i][j + 1];
        }
      }
    }
    return paths[0][0];
  }
};
