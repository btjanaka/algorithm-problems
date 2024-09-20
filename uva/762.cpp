// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 762
// Title: We Ship Cheap
// Link:
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=703
// Idea: BFS from the start to the end while keeping track of parents.
// Difficulty: Medium
// Tags:
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int links;
  bool first = true;
  while (cin >> links) {
    // Construct graph.
    unordered_map<string, vector<string>> g;
    string a, b;
    for (int i = 0; i < links; ++i) {
      cin >> a >> b;
      if (g.find(a) == g.end()) g[a] = {};
      if (g.find(b) == g.end()) g[b] = {};
      g[a].push_back(b);
      g[b].push_back(a);
    }

    string start, end;
    cin >> start >> end;

    // BFS from start to end.
    queue<string> q;
    unordered_map<string, string> parents;
    unordered_set<string> visited;
    q.push(start);
    visited.insert(start);
    bool found = false;
    while (!q.empty() && !found) {
      string cur = q.front();  // If cur is in the queue, it has already been
                               // marked as visited.
      q.pop();

      for (const auto& nbr : g[cur]) {
        if (visited.find(nbr) == visited.end()) {
          q.push(nbr);
          visited.insert(nbr);
          parents[nbr] = cur;

          if (nbr == end) {
            found = true;
            break;
          }
        }
      }
    }

    if (first) {
      first = false;
    } else {
      cout << "\n";
    }

    if (found) {
      vector<string> path;
      string cur = end;
      while (parents.find(cur) != parents.end()) {
        path.push_back(cur);
        cur = parents[cur];
      }
      path.push_back(start);
      for (int i = path.size() - 1; i > 0; --i) {
        cout << path[i] << ' ' << path[i - 1] << '\n';
      }
    } else {
      cout << "No route"
           << "\n";
    }
  }

  return 0;
}
