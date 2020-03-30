// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) journey-to-the-moon
// Title: Journey to the Moon
// Link: https://www.hackerrank.com/challenges/journey-to-the-moon/problem
// Idea: The pairs of astronauts form a graph. Find connected components to find
// the number of astronauts from each country.
// Difficulty: medium
// Tags: graph, connected-components, breadth-first-search
#include <bits/stdc++.h>

using namespace std;

int bfs(vector<set<int>>& astro, set<int>& visited, int start) {
  int size = 0;
  queue<int> to_visit;
  to_visit.push(start);
  while (!to_visit.empty()) {
    int curr = to_visit.front();
    visited.insert(curr);
    to_visit.pop();
    for (int child : astro[curr]) {
      if (visited.find(child) == visited.end()) to_visit.push(child);
      visited.insert(child);  // need to insert no matter what because other
                              // nodes in queue may have this as a child
    }
    ++size;
  }
  return size;
}

vector<long long> calc_comp(vector<set<int>>& astro) {
  set<int> visited;
  vector<long long> sizes;
  for (int i = 0; i < astro.size(); ++i) {
    if (visited.find(i) == visited.end()) {
      sizes.push_back(bfs(astro, visited, i));
    }
  }
  return sizes;
}

int main() {
  int n, p;
  scanf("%d %d", &n, &p);
  vector<set<int>> astro(n);
  int a1, a2;
  for (int i = 0; i < p; ++i) {
    scanf("%d %d", &a1, &a2);
    astro[a1].insert(a2);
    astro[a2].insert(a1);
  }
  vector<long long> comp = calc_comp(astro);
  long long pairs = 0;
  long long tot = 0;
  tot = comp[0];
  pairs = 0;
  for (int i = 1; i < comp.size(); ++i) {
    pairs += comp[i] * tot;
    tot += comp[i];
  }
  printf("%lld\n", pairs);
  return 0;
}
