// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) highscore
// Title: High Score
// Link: https://open.kattis.com/problems/highscore
// Idea: Always pick the closest item to switch. Break ties by either always
// moving left or always moving right.
// Difficulty: medium
// Tags: implementation, greedy
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

// Calculate the cost of moving left and right with the joystick. This works by
// finding the closest character on the left and right that needs changing from
// the given position, and moving left or right as appropriate. Ties between
// left and right are broken by either always moving left or always moving
// right, as indicated by moveLeftOnTie. We do not want to switch between moving
// left and right on ties because that means we are going back the way we came.
int calc_movement(const string& s, int n, int to_switch, bool moveLeftOnTie) {
  int moves = 0;
  int switch_count = 0;
  int left = 0;
  int right = 0;
  int cur_pos = 0;
  vector<bool> switched(n, false);

  while (switch_count != to_switch) {
    left = cur_pos;
    right = cur_pos;
    int dist = 0;

    while (true) {
      if (s[left] != 'A' && !switched[left]) break;
      if (s[right] != 'A' && !switched[right]) break;
      left = left == 0 ? n - 1 : left - 1;
      right = right == n - 1 ? 0 : right + 1;
      ++dist;
    }

    bool left_hit = s[left] != 'A' && !switched[left];
    bool right_hit = s[right] != 'A' && !switched[right];

    if (left_hit && right_hit) {
      if (moveLeftOnTie) {
        cur_pos = left;
      } else {
        cur_pos = right;
      }
    } else if (left_hit) {
      cur_pos = left;
    } else {
      cur_pos = right;
    }

    ++switch_count;
    switched[cur_pos] = true;
    moves += dist;
  }
  return moves;
}

// Cost of moving joystick forward or backward to make the given character from
// 'A'.
int char_cost(char ch) {
  int forward_cost = ch - 'A';
  int backward_cost = 'Z' - ch + 1;
  return min(forward_cost, backward_cost);
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int ca;
  cin >> ca;
  string s;
  while (ca--) {
    cin >> s;
    int n = (int)s.size();
    int individual_char_cost = 0;
    int to_switch = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] != 'A') {
        individual_char_cost += char_cost(s[i]);
        ++to_switch;
      }
    }

    int movement_cost = min(calc_movement(s, n, to_switch, true),
                            calc_movement(s, n, to_switch, false));

    cout << individual_char_cost + movement_cost << '\n';
  }

  return 0;
}
