// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) acm-icpc-team
// Title: ACM ICPC Team
// Link: https://www.hackerrank.com/challenges/acm-icpc-team/problem
// Idea: Try every possible team by looking at all pairs of people and seeing
// how many topics they know.
// Difficulty: easy
// Tags: implementation
#include <bits/stdc++.h>

using namespace std;
using person = bitset<500>;

int main() {
  // Input.
  int n, m;
  cin >> n >> m;
  vector<person> people(n);
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    people[i] = person(s);
  }

  // Try every possible team.
  int max_topics = 0;
  int num_max = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int topics = (people[i] | people[j]).count();  // See std::bitset
      if (topics > max_topics) {
        max_topics = topics;
        num_max = 1;
      } else if (topics == max_topics) {
        ++num_max;
      }
    }
  }
  cout << max_topics << '\n' << num_max << endl;

  return 0;
}
