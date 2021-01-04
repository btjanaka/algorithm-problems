// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) maximum-cost-queries
// Title: Super Maximum Cost Queries
// Link: https://www.hackerrank.com/challenges/maximum-cost-queries/problem
// Idea: Since this is a tree, there is exactly one path from each node to each
// other node. Using a union find, we can gradually add in the edges in
// increasing order. Each time we add in an edge e with weight w, we can figure
// out how many paths have cost w by multiplying the sizes of the two components
// we just connected. As such, we will end up with a mapping of how many edges
// have cost a, cost b, etc. When we receive a query, we just need to count up
// how many entries have cost between L and R.
// Difficulty: medium
// Tags: union-find
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

struct UnionFind {
  vector<int> p, ranks, sizes;
  UnionFind(int n) : p(n), ranks(n, 0), sizes(n, 1) {
    iota(p.begin(), p.end(), 0);
  }
  int find(int i) { return i == p[i] ? i : (p[i] = find(p[i])); }

  // Returns the number of new paths that were created.
  ll join(int i, int j) {
    int x = find(i), y = find(j);
    if (x != y) {
      ll new_paths = (ll)sizes[x] * (ll)sizes[y];
      if (ranks[x] > ranks[y]) {
        p[y] = x;
        sizes[x] += sizes[y];
      } else {
        if (ranks[x] == ranks[y]) {
          ++ranks[y];
        }
        p[x] = y;
        sizes[y] += sizes[x];
      }
      return new_paths;
    }
    return 0;
  }
};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  // Input edges.
  int n, q, u, v, w;
  cin >> n >> q;
  vector<pair<int, ii>> edges;  // (weight, (u, v))
  for (int e = 1; e < n; ++e) {
    cin >> u >> v >> w;
    --u;
    --v;
    edges.push_back({w, {u, v}});
  }
  sort(edges.begin(), edges.end());  // Sort edges by weight.

  // Count number of paths with each cost.
  UnionFind uf(n);
  map<int, ll> costs;  // cost -> num occurrences, note this is a sorted map.
  for (const auto& e : edges) {
    w = e.first;
    u = e.second.first;
    v = e.second.second;
    costs[w] += uf.join(u, v);  // costs[w] inits to 0 if it does not exist.
  }

  // Each entry stores the number of paths with cost less than or equal to the
  // cost.
  map<int, ll> cum_costs;
  cum_costs[0] = 0;  // Base for accumulation - L and R are always greater than
                     // 1, so this is safe.
  ll prev_sum = 0;
  int min_cost = costs.begin()->first;
  int max_cost = min_cost;
  for (const auto& c :
       costs) {  // Iterates in key order (i.e. increasing cost).
    ll next_sum = c.second + prev_sum;
    cum_costs[c.first] = next_sum;
    prev_sum = next_sum;
    max_cost = c.first;
  }

  // Process queries.
  for (int x = 0; x < q; ++x) {
    int L, R;
    cin >> L >> R;
    ll ans = 0;
    if (L < min_cost && R > max_cost) {
      // The range wraps all costs, so grab everything.
      ans = cum_costs[max_cost];
    } else if (L < min_cost && R <= max_cost) {
      // Only the left bound is outside possible costs.
      // Find the element greater than R and go to the previous one.
      ans = (--cum_costs.upper_bound(R))->second;
    } else if (L >= min_cost && R > max_cost) {
      // Only the right bound is outside possible costs.
      // Find the element greater or equal to L and go to the previous one.
      ll lower_sum = (--cum_costs.lower_bound(L))->second;
      ans = cum_costs[max_cost] - lower_sum;
    } else {
      ans = (--cum_costs.upper_bound(R))->second -
            (--cum_costs.lower_bound(L))->second;
    }
    cout << ans << "\n";
  }

  return 0;
}
