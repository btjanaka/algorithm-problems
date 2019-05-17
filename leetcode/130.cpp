// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 130
// Title: Surrounded Regions
// Link: https://leetcode.com/problems/surrounded-regions/
// Idea: DFS all the edges to find O's that cannot be marked.
// Difficulty: medium
// Tags: graph
class Solution {
 public:
  void mark(vector<vector<char>>& board, vector<vector<char>>& cannot_capture,
            int r, int c) {
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() ||
        cannot_capture[r][c] != '0' || board[r][c] != 'O')
      return;

    cannot_capture[r][c] = board[r][c] == 'O' ? '2' : '1';
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};
    for (int i = 0; i < 4; ++i) {
      mark(board, cannot_capture, r + dr[i], c + dc[i]);
    }
  }

  void solve(vector<vector<char>>& board) {
    if (board.size() == 0) return;

    int r = board.size(), c = board[0].size();
    vector<vector<char>> cannot_capture(r, vector<char>(c, '0'));
    for (int i = 0; i < c; ++i) {
      mark(board, cannot_capture, 0, i);
      mark(board, cannot_capture, r - 1, i);
    }
    for (int i = 0; i < r; ++i) {
      mark(board, cannot_capture, i, 0);
      mark(board, cannot_capture, i, c - 1);
    }

    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (cannot_capture[i][j] != '2') {
          board[i][j] = 'X';
        }
      }
    }
  }
};
