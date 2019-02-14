// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 200
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s, prev;
  unordered_map<char, unordered_set<char>> g;
  unordered_map<char, int> in;

  // input - find characters that are less than the others - similar to strcmp
  bool first = true;
  while (cin >> s && s[0] != '#') {
    if (first) {
      first = false;
    } else {
      int i;
      for (i = 0; i < s.size() && i < prev.size() && prev[i] == s[i]; ++i) {
      }
      if (i < s.size() && i < prev.size()) {
        if (g.find(prev[i]) == g.end()) {
          g[prev[i]] = {};
          in[prev[i]] = 0;
        }
        if (g.find(s[i]) == g.end()) {
          g[s[i]] = {};
          in[s[i]] = 0;
        }
        if (g[prev[i]].find(s[i]) == g[prev[i]].end()) {
          ++in[s[i]];
          g[prev[i]].insert(s[i]);
        }
      }
    }
    prev = s;
  }

  // topo sort
  queue<char> visit;
  for (auto& x : in) {
    if (x.second == 0) {
      visit.push(x.first);
    }
  }
  while (!visit.empty()) {
    char cur = visit.front();
    visit.pop();
    putchar(cur);
    for (char ch : g[cur]) {
      --in[ch];
      if (in[ch] == 0) {
        visit.push(ch);
      }
    }
  }
  putchar('\n');

  return 0;
}
