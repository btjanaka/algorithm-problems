// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) Roads and Libraries
#include <bits/stdc++.h>

using namespace std;

int bfs(int start, vector<unordered_set<int>>& graph,
        unordered_set<int>& visited) {
  queue<int> to_visit;
  to_visit.push(start);
  visited.insert(start);
  int count = 0;
  while (!to_visit.empty()) {
    int cur = to_visit.front();
    to_visit.pop();
    count++;
    for (int child : graph[cur]) {
      if (visited.find(child) == visited.end()) {
        visited.insert(child);
        to_visit.push(child);
      }
    }
  }
  return count;
}

int main() {
  int q;
  cin >> q;
  while (q--) {
    int cities, roads, c_lib, c_road;
    scanf("%d %d %d %d", &cities, &roads, &c_lib, &c_road);
    vector<unordered_set<int>> graph(cities, unordered_set<int>());
    for (int i = 0; i < roads; ++i) {
      int n1, n2;
      scanf("%d %d", &n1, &n2);
      --n1, --n2;
      graph[n1].insert(n2);
      graph[n2].insert(n1);
    }

    // find connected components
    vector<int> comps;
    unordered_set<int> visited;
    for (int i = 0; i < cities; ++i) {
      if (visited.find(i) == visited.end())
        comps.push_back(bfs(i, graph, visited));
    }

    // calc diff costs
    long long no_road = 0;
    for_each(comps.begin(), comps.end(), [&](int i) { no_road += i * c_lib; });
    long long with_road = 0;
    for_each(comps.begin(), comps.end(),
             [&](int i) { with_road += c_lib + (i - 1) * c_road; });
    printf("%lld\n", min(no_road, with_road));
  }
  return 0;
}
