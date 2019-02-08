// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 599
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int bfs(int start, vector<vector<int>>& graph, unordered_set<int>& visited) {
  int tot = 0;
  queue<int> to_visit;
  to_visit.push(start);
  while (!to_visit.empty()) {
    ++tot;
    int cur = to_visit.front();
    to_visit.pop();
    for (int child : graph[cur]) {
      if (visited.find(child) == visited.end()) {
        visited.insert(child);
        to_visit.push(child);
      }
    }
  }
  return tot;
}

int main() {
  int ca;
  GET(ca);
  getchar();
  char buf[100];
  while (ca--) {
    vector<vector<int>> graph(26);
    bool used[26];

    // input edges
    char a, b;
    while (fgets(buf, 100, stdin) && buf[0] != '*') {
      sscanf(buf, "(%c,%c)", &a, &b);
      a -= 'A';
      b -= 'A';
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    // find used nodes
    fgets(buf, 100, stdin);
    memset(used, false, sizeof(used));
    char* token = strtok(buf, ",\n");
    while (token != NULL) {
      used[token[0] - 'A'] = true;
      token = strtok(NULL, ",\n");
    }

    // find results
    int trees = 0;
    int acorns = 0;
    unordered_set<int> visited;
    for (int i = 0; i < 26; ++i) {
      if (used[i] && visited.find(i) == visited.end()) {
        visited.insert(i);
        int num = bfs(i, graph, visited);
        if (num == 1)
          ++acorns;
        else
          ++trees;
      }
    }

    printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
  }
  return 0;
}
