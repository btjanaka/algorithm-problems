// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 79
// Title: Word Search
// Link: https://leetcode.com/problems/word-search
// Idea: Use DFS to check if a word starting at a given index matches.
// Difficulty: medium
// Tags: graph, depth-first-search
class Solution {
 public:
  int dr[4] = {-1, 0, 1, 0};
  int dc[4] = {0, -1, 0, 1};

  bool dfs(int r, int c, int i, const vector<vector<char>>& board,
           const string& word, vector<vector<bool>>& visited) {
    if (i == word.size()) return true;
    if (!(r < board.size() && r >= 0 && c < board[0].size() && c >= 0) ||
        visited[r][c])
      return false;
    visited[r][c] = true;

    bool ok = false;
    if (word[i] == board[r][c]) {
      for (int j = 0; j < 4; ++j) {
        if (!ok) ok |= dfs(dr[j] + r, dc[j] + c, i + 1, board, word, visited);
      }
    }
    visited[r][c] = false;
    return ok;
  }

  bool exist(vector<vector<char>>& board, const string& word) {
    int rows = board.size();
    int cols = board[0].size();
    if (word.size() > rows * cols) return false;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    for (int r = 0; r < rows; ++r) {
      for (int c = 0; c < cols; ++c) {
        if (board[r][c] == word[0]) {
          if (dfs(r, c, 0, board, word, visited)) return true;
        }
      }
    }
    return false;
  }
};
