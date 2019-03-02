// Author: btjanaka (Bryon Tjanaka)
// Problem: (hash code) pizza
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

bool bound(int n, int lo, int hi) { return n >= lo && n <= hi; }

pair<int, string> score(int R, int C, int L, int H,
                        const vector<vector<int>>& solution,
                        const vector<string>& pizza) {
  vector<vector<bool>> visited(R, vector<bool>(C, false));
  int res = 0;
  for (auto& sol : solution) {
    int ri = min(sol[0], sol[2]);
    int rf = max(sol[0], sol[2]);
    int ci = min(sol[1], sol[3]);
    int cf = max(sol[1], sol[3]);

    if (!bound(ri, 0, R - 1) || !bound(rf, 0, R - 1) || !bound(ci, 0, C - 1) ||
        !bound(cf, 0, C - 1)) {
      return {-1, "out of bounds"};
    }

    int cells = 0;
    int tomatoes = 0;
    int mushrooms = 0;

    for (int r = ri; r <= rf; ++r) {
      for (int c = ci; c <= cf; ++c) {
        if (visited[r][c]) return {-1, "overlap"};
        visited[r][c] = true;

        if (pizza[r][c] == 'T') {
          ++tomatoes;
        } else {
          ++mushrooms;
        }

        ++cells;
        ++res;
      }
    }

    if (cells > H) return {-1, "too large"};
    if (tomatoes < L) return {-1, "too few tomatoes"};
    if (mushrooms < L) return {-1, "too few mushrooms"};
  }
  return {res, "ok"};
}

void print_solution(vector<vector<int>>& solution) {
  printf("%u\n", solution.size());
  for (auto x : solution) {
    printf("%d %d %d %d\n", x[0], x[1], x[2], x[3]);
  }
}

int main() {
  int R, C, L, H;
  GET(R);
  GET(C);
  GET(L);
  GET(H);
  vector<string> pizza;
  for (int i = 0; i < R; ++i) {
    pizza.push_back("");
    getline(cin, pizza.back());
  }

  // vector<vector<int>> solution = {
  //     {0, 0, 2, 1},
  //     {0, 2, 2, 2},
  //     {0, 3, 2, 4},
  // };
  // pair<int, string> res = score(R, C, L, H, solution, pizza);
  // printf("score: %d detail: %s\n", res.first, res.second.c_str());

  vector<vector<int>> solution = generate_random(R, C, L, H, pizza);

  print_solution(solution);

  return 0;
}
