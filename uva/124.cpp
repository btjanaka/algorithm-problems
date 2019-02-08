// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 124
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

// recursive topo sort where we have to keep track of all possible sequences of
// characters - we use in to keep track of which chars to use next
void topo(string& s, unordered_set<char>& visited,
          unordered_map<char, unordered_set<char>>& g, map<char, int>& in,
          int n) {
  if (s.size() == n) {
    printf("%s\n", s.c_str());
    return;
  }

  // guaranteed sorted because |in| is a map
  for (auto&& x : in) {
    if (x.second == 0 && visited.find(x.first) == visited.end()) {
      for (char ch : g[x.first]) --in[ch];
      s.push_back(x.first);
      visited.insert(x.first);
      topo(s, visited, g, in, n);
      visited.erase(x.first);
      s.pop_back();
      for (char ch : g[x.first]) ++in[ch];
    }
  }
}

int main() {
  char buf[1000];
  bool first = true;
  while (fgets(buf, 1000, stdin) != NULL) {
    // input
    unordered_map<char, unordered_set<char>> g;
    map<char, int> in;  // in-degree

    for (int i = 0; buf[i] != '\n'; ++i) {
      if (buf[i] != ' ') {
        g[buf[i]] = {};
        in[buf[i]] = 0;
      }
    }

    fgets(buf, 1000, stdin);
    int cur = 0;
    char a, b;
    for (int i = 0; buf[i] != '\n'; ++i) {
      if (buf[i] != ' ') {
        if (cur % 2 == 0)
          a = buf[i];
        else {
          b = buf[i];
          // account for duplicates
          if (g[a].find(b) == g[a].end()) {
            ++in[b];
            g[a].insert(b);
          }
        }
        ++cur;
      }
    }

    // output
    if (first)
      first = false;
    else
      printf("\n");
    string s;
    unordered_set<char> visited;
    topo(s, visited, g, in, (int)g.size());
  }
  return 0;
}
