// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 872
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int solcount;

// recursive backtracking with topological sort
void topo(string& s, unordered_map<char, unordered_set<char>>& g,
          map<char, int>& in, unordered_set<char>& visited, int cur, int n) {
  if (cur == n) {
    ++solcount;
    printf("%s", s.c_str());
    return;
  }

  for (const auto& x : in) {
    if (x.second == 0 && visited.find(x.first) == visited.end()) {
      visited.insert(x.first);
      s.push_back(x.first);
      s.push_back(cur == n - 1 ? '\n' : ' ');
      for (char ch : g[x.first]) --in[ch];
      topo(s, g, in, visited, cur + 1, n);
      for (char ch : g[x.first]) ++in[ch];
      s.pop_back();
      s.pop_back();
      visited.erase(x.first);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ca;
  string s;
  cin >> ca;
  getline(cin, s);
  getline(cin, s);
  while (ca--) {
    unordered_map<char, unordered_set<char>> g;
    map<char, int> in;

    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ') {
        g[s[i]] = {};
        in[s[i]] = 0;
      }
    }

    int ci = 0;
    char c1, c2;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ' && s[i] != '<') {
        if (ci % 2 == 0) {
          c1 = s[i];
        } else {
          c2 = s[i];
          if (g[c1].find(c2) == g[c1].end()) {
            ++in[c2];
            g[c1].insert(c2);
          }
        }
        ++ci;
      }
    }

    solcount = 0;
    string s;
    int n = g.size();
    unordered_set<char> visited;
    topo(s, g, in, visited, 0, n);

    if (solcount == 0) printf("NO\n");

    if (ca) {
      getline(cin, s);
      printf("\n");
    }
  }
  return 0;
}
