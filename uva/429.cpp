// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 429
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int bfs(const string& start, const string& end,
        unordered_map<string, unordered_set<string>>& g) {
  unordered_set<string> visit;
  visit.insert(start);
  unordered_set<string> visited;
  visited.insert(start);
  unordered_map<string, int> dists;
  dists[start] = 0;

  int dist = 0;
  for (dist = 0; !visit.empty(); ++dist) {
    unordered_set<string> next_visit;
    for (const string& u : visit) {
      if (u == end) return dist;
      for (const string& v : g[u]) {
        if (visited.find(v) == visited.end()) {
          next_visit.insert(v);
          visited.insert(v);
        }
      }
    }
    visit = std::move(next_visit);
  }

  return dist;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ca;
  cin >> ca;
  cin.get();
  cin.get();
  string s;

  while (ca--) {
    // graph input
    vector<string> words;
    unordered_map<string, unordered_set<string>> g;
    while (getline(cin, s) && s != "*") {
      words.push_back(s);
      g[s] = {};
    }
    for (int i = 0; i < words.size(); ++i) {
      for (int j = i + 1; j < words.size(); ++j) {
        if (words[i].size() != words[j].size()) continue;
        int diff = 0;
        for (int k = 0; k < words[i].size(); ++k) {
          diff += words[i][k] != words[j][k];
        }
        if (diff == 1) {
          g[words[i]].insert(words[j]);
          g[words[j]].insert(words[i]);
        }
      }
    }

    // queries
    string start, end;
    while (getline(cin, s) && s != "") {
      stringstream ss(s);
      ss >> start >> end;

      printf("%s %s %d\n", start.c_str(), end.c_str(), bfs(start, end, g));
    }

    if (ca) printf("\n");
  }
  return 0;
}
