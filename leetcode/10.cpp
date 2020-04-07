// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 10
// Title: Regular Expression Matching
// Link: https://leetcode.com/problems/regular-expression-matching
// Idea: Simulate with an NFA (non-deterministic finite automaton). There's also
// some DP methods, but this is cooler :p
// Difficulty: hard
// Tags: dynamic-programming, finite-state-machine
class Solution {
 public:
  bool isMatch(string s, string p) {
    // separate into tokens - easier to parse
    vector<pair<char, bool>> regex;
    for (int i = 0; i < p.size(); ++i) {
      bool star = false;
      if (i + 1 < p.size() && p[i + 1] == '*') star = true;
      regex.push_back({p[i], star});
      if (star) ++i;
    }

    // initial states - include any stars at the beginning of the string
    unordered_set<int> states = {0};
    for (int i = 1; i <= regex.size() && regex[i - 1].second; ++i) {
      states.insert(i);
    }

    // simulate the NFA
    for (char ch : s) {
      // debugging
      // printf("%c:", ch);
      // for(int cur : states) printf(" %d", cur);
      // printf("\n");

      // find the next set of states
      unordered_set<int> next;
      for (int cur : states) {
        if (cur == regex.size()) continue;  // the last state is a dead state
        bool star = regex[cur].second;
        if (regex[cur].first == '.' || regex[cur].first == ch) {
          next.insert(cur + 1);
          if (star) next.insert(cur);
        }
      }

      // add in epsilon transitions
      unordered_set<int> next_with_epsilon;
      for (int cur : next) {
        next_with_epsilon.insert(cur);
        for (int i = cur + 1; i <= regex.size() && regex[i - 1].second; ++i) {
          next_with_epsilon.insert(i);
        }
      }

      states = move(next_with_epsilon);
    }

    return states.find(regex.size()) != states.end();
  }
};
