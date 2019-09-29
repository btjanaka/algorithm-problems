// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 1210
// Title: Minimum Moves to Reach Target with Rotations
// Link:
// https://leetcode.com/problems/minimum-moves-to-reach-target-with-rotations/
// Idea: This can be accomplished via a BFS based on the snake moves. The
// implementation can be a bit tricky though.
// Difficulty: medium
// Tags: bfs
class Solution {
 public:
  static const int H = 0;
  static const int V = 1;

  struct snake {
    int r;
    int c;
    int orientation;
    int moves;
  };

  bool valid(int r, int c, vector<vector<int>>& grid, int n) {
    return !(r >= n || c >= n || grid[r][c]);
    // r and c should always be >= 0
  }

  int minimumMoves(vector<vector<int>>& grid) {
    int n = grid.size();
    queue<snake> q;
    bool visited[n][n][2];  // efficient and easy way to keep track of visited
    memset(visited, false, sizeof(visited));

    snake initial = {0, 0, H, 0};
    q.push(initial);
    visited[0][0][H] = true;

    while (!q.empty()) {
      snake cur = q.front();
      q.pop();

      if (cur.r == n - 1 && cur.c == n - 2 && cur.orientation == H) {
        return cur.moves;
      } else {
        int r = cur.r, c = cur.c, orientation = cur.orientation,
            moves = cur.moves;
        if (orientation == H) {
          // Down, right, clockwise
          if (valid(r + 1, c, grid, n) && valid(r + 1, c + 1, grid, n) &&
              !visited[r + 1][c][H]) {
            q.push({r + 1, c, H, moves + 1});
            visited[r + 1][c][H] = true;
          }
          if (valid(r, c + 2, grid, n) && !visited[r][c + 1][H]) {
            q.push({r, c + 1, H, moves + 1});
            visited[r][c + 1][H] = true;
          }
          if (valid(r + 1, c, grid, n) && valid(r + 1, c + 1, grid, n) &&
              !visited[r][c][V]) {
            q.push({r, c, V, moves + 1});
            visited[r][c][V] = true;
          }
        } else {
          // orientation == V
          // Down, right, counterclockwise
          if (valid(r + 2, c, grid, n) && !visited[r + 1][c][V]) {
            q.push({r + 1, c, V, moves + 1});
            visited[r + 1][c][V] = true;
          }
          if (valid(r, c + 1, grid, n) && valid(r + 1, c + 1, grid, n) &&
              !visited[r][c + 1][V]) {
            q.push({r, c + 1, V, moves + 1});
            visited[r][c + 1][V] = true;
          }
          if (valid(r, c + 1, grid, n) && valid(r + 1, c + 1, grid, n) &&
              !visited[r][c][H]) {
            q.push({r, c, H, moves + 1});
            visited[r][c][H] = true;
          }
        }
      }
    }
    return -1;
  }
};
