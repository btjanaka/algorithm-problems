// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 773
// Title: Sliding Puzzle
// Link: https://leetcode.com/problems/sliding-puzzle/
// Idea: Implement A* search with Manhattan distance heuristic. May be able to
// use other less efficient algorithms.
// Difficulty: Hard
// Tags: A*, a-star
class Solution {
 public:
  inline bool is_solution(const string& board) { return board == "123450"; }

  // Calculate the heuristic of Manhattan distance.
  inline int heuristic(const string& board) {
    int h = 0;
    for (int i = 0; i < 6; ++i) {
      int tile = board[i];
      if (tile == '0') continue;
      tile -= '0' + 1;
      int r = i / 3;
      int c = i % 3;
      int r_tile = tile / 3;
      int c_tile = tile % 3;
      h += abs(r - r_tile) + abs(c - c_tile);
    }
    return h;
  }

  static constexpr char MOVES[4] = {'r', 'l', 'u', 'd'};
  static constexpr int R[4] = {0, 0, 1, -1};
  static constexpr int C[4] = {1, -1, 0, 0};
  // Carries out the move on the given board. Returns empty string if not
  // possible.
  inline string make_move(const string& board, int move_index) {
    // Find the 'x'.
    int r, c, x_i;
    for (int i = 0; i < 9; ++i) {
      if (board[i] == '0') {
        r = i / 3;
        c = i % 3;
        x_i = i;
        break;
      }
    }

    // Check if the move is legal - if so, make it.
    int r2 = r + R[move_index];
    int c2 = c + C[move_index];
    if (r2 < 0 || r2 > 1 || c2 < 0 || c2 > 2) {
      return "";
    } else {
      int swap_i = r2 * 3 + c2;
      string new_board = board;
      swap(new_board[x_i], new_board[swap_i]);
      return new_board;
    }
  }

  int slidingPuzzle(vector<vector<int>>& board_nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string initial = "";
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        initial.push_back('0' + board_nums[i][j]);
      }
    }

    // States we have seen already.
    unordered_set<string> visited;
    // Contains cost f = g + h, h, board.
    using pq_data = tuple<int, int, string>;
    priority_queue<pq_data, vector<pq_data>, greater<pq_data>> pq;

    // A* search
    int h_0 = heuristic(initial);
    pq.push({h_0, h_0, initial});
    int ret = -1;
    while (!pq.empty()) {
      int f_prev;
      int h_prev;
      string cur;
      tie(f_prev, h_prev, cur) = pq.top();
      pq.pop();

      // This node must have bad cost if we saw it already, so we just skip it.
      if (visited.find(cur) != visited.end()) continue;
      visited.insert(cur);

      int g_prev = f_prev - h_prev;

      // Goal test.
      if (is_solution(cur)) {
        ret = g_prev;
        break;
      }

      // Expand cur to get children boards.
      int g = g_prev + 1;
      for (int i = 0; i < 4; ++i) {
        string child = make_move(cur, i);
        if (child.empty()) continue;
        int h = heuristic(child);
        g = g_prev + 1;
        int f = h + g;
        pq.push({f, h, child});
      }
    }

    return ret;
  }
};
