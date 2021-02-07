// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) largest-rectangle
// Title: Largest Rectangle
// Link: https://www.hackerrank.com/challenges/largest-rectangle/problem
// Idea: Keep a stack with the building sizes. Each time the building size
// increases or stays the same, we push a building onto this stack. When the
// building size decreases, we pop from this stack until we find a building that
// is shorter than the current building. Essentially, the increasing building
// sizes get "stopped" by a decreased building, and when that happens we need to
// "go back" and see what sizes are possible.
// Difficulty: medium
// Tags: stack
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, h;
  cin >> n;
  vector<pair<int, int>> s;  // {height, count}

  // Iterate thru other elements.
  int max_size = 0;
  for (int i = 0; i < n; ++i) {
    cin >> h;

    // No elements in stack.
    if (s.empty()) {
      s.push_back({h, 1});
      continue;
    }

    if (h == s.back().first) {
      // Equal - increase count of element at top of stack.
      ++s.back().second;
    } else if (h > s.back().first) {
      // Increasing - new instance of element.
      s.push_back({h, 1});
    } else {
      // Decreasing - complicated. Pop until find an element that is
      // >=, while accounting for size.
      max_size = max(max_size, h);
      int sum = 0;
      while (!s.empty() && s.back().first >= h) {
        sum += s.back().second;
        max_size = max(max_size, sum * s.back().first);
        s.pop_back();
      }
      // Preserve "compressed" version of the element.
      s.push_back({h, sum + 1});
      max_size = max(max_size, h * (sum + 1));
    }

    // Nice debugging code.
    // cout << "s (" << i << "):";
    // for (const auto& x : s) cout << " {" << x.first << ", " << x.second <<
    // "}"; cout << endl;
  }

  // Clean up -- at this point, all remaining are guaranteed to be in increasing
  // order.
  int sum = 0;
  while (!s.empty()) {
    sum += s.back().second;
    max_size = max(max_size, sum * s.back().first);
    s.pop_back();
  }

  cout << max_size << endl;

  return 0;
}
