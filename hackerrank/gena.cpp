// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) gena
// Title: Gena Playing Hanoi
// Link: https://www.hackerrank.com/challenges/gena/problem
// Idea: Perform a breadth first search beginning at the starting position given
// by Gena. When generating the nodes in the graph for BFS, we look at all valid
// moves of the discs; these come from moving a smaller disc onto a larger disc.
// We can use an integer bitset to represent the nodes in the graph; the bitset
// contains the pole on which each of the n items is placed. Since n <= 10 and
// the pole number only takes up 2 bits (0-3 for 4 poles), we use just 20 bits.
// We need a bitset since we want to keep track of the configurations we have
// already checked; if we were doing this in Python we could use a tuple with 10
// values, for instance.
// Difficulty: medium
// Tags: bfs, complete-search, implementation
#include <bits/stdc++.h>

using namespace std;

// Modifies the bitset to indicate that item idx is at position pos.
// pos and idx should be 0-indexed.
int setPos(int bitset, int idx, int pos) {
  // Clear the bits at the position.
  int mask = ~(3 << (2 * idx));  // 3 -> 0b11
  bitset = bitset & mask;
  return bitset | (pos << (2 * idx));  // Fill in the bits.
}

// Get the item at the index in the bitset.
int getPos(int bitset, int idx) {
  int mask = 3 << (2 * idx);
  return (bitset & mask) >> (2 * idx);
}

int main() {
  int n;
  while (cin >> n) {
    int goal = 0;
    for (int i = 0; i < n; ++i) {
      goal = setPos(goal, i, 0);
    }

    int start = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      start = setPos(start, i, x - 1);
    }

    // BFS for the shortest path to the goal.
    int shortest = -1;
    unordered_set<int> visited;
    queue<pair<int, int>> q;  // bitset, path length
    q.push({start, 0});
    visited.insert(start);
    int tops[4];  // Disc at top of each pole.
    while (!q.empty()) {
      int cur, length;
      tie(cur, length) = q.front();
      q.pop();
      if (cur == goal) {
        shortest = length;
        break;
      }

      // Find the disc at the top of each pole.
      tops[0] = tops[1] = tops[2] = tops[3] = -1;
      for (int i = n - 1; i >= 0; --i) {
        tops[getPos(cur, i)] =
            i;  // The smaller i's will preempt the larger i's.
      }

      // Try all possible poles for the top discs.
      for (int i = 0; i < 4; ++i) {
        if (tops[i] == -1) continue;  // No top disc.
        for (int j = 0; j < 4; ++j) {
          if (i == j) continue;  // Skip same pole.
          if (tops[j] == -1 || tops[i] < tops[j]) {
            int next = setPos(cur, tops[i], j);  // Move the item to pole j.
            if (visited.find(next) == visited.end()) {
              q.push({next, length + 1});
              visited.insert(next);
            }
          }
        }
      }
    }

    if (shortest == -1) {
      cout << "???\n";  // Not specified in the problem stmt.
    } else {
      cout << shortest << '\n';
    }
  }

  return 0;
}
