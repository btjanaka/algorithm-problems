// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 210
// Title: Course Schedule II
// Link: https://leetcode.com/problems/course-schedule-ii
// Idea: Topological sort, but be careful about cycles.
// Difficulty: medium
// Tags: graph, topological-sort
class Solution {
 private:
  static constexpr int UNVISIT = 0;
  static constexpr int ON_PATH = 1;
  static constexpr int VISITED = 2;

 public:
  // returns whether there was a cycle (i.e. failure) - otherwise performs topo
  // sort by adding to the result
  bool dfs(int start, vector<int>& state, vector<vector<int>>& g,
           vector<int>& res) {
    if (state[start] == ON_PATH) return false;
    state[start] = ON_PATH;

    for (int v : g[start]) {
      if (state[v] != VISITED) {
        if (!dfs(v, state, g, res)) return false;
      }
    }

    state[start] = VISITED;
    res.push_back(start);
    return true;
  }

  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> res;
    vector<vector<int>> g(numCourses);
    for (pair<int, int>& p : prerequisites) {
      g[p.second].push_back(p.first);
    }

    bool ok = true;
    vector<int> state(numCourses, UNVISIT);
    for (int i = 0; i < numCourses; ++i) {
      if (state[i] != VISITED) {
        if (!dfs(i, state, g, res)) {
          ok = false;
          break;
        }
      }
    }

    if (!ok) return {};
    for (int i = 0; i < numCourses / 2; ++i)
      swap(res[i], res[numCourses - i - 1]);
    return res;
  }
};
