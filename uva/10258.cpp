// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10258
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

struct team {
  int num;
  int solved;
  int penalty;
  int subs;
  bool ind_solve[10];
  int ind_penalty[10];

  team(int num_) : num(num_), solved(0), penalty(0), subs(0) {
    memset(ind_solve, false, sizeof(ind_solve));
    memset(ind_penalty, 0, sizeof(ind_penalty));
  }

  void calc() {
    solved = 0;
    penalty = 0;
    for (int i = 1; i <= 9; ++i) {
      if (ind_solve[i]) {
        ++solved;
        penalty += ind_penalty[i];
      }
    }
  }

  bool operator<(const team& rhs) {
    if (solved != rhs.solved) return solved > rhs.solved;
    if (penalty != rhs.penalty) return penalty < rhs.penalty;
    if (subs > 0 && rhs.subs == 0) return true;
    if (num != rhs.num) return num < rhs.num;
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int ca;
  cin >> ca;
  string s;
  getline(cin, s);
  getline(cin, s);
  bool first = true;

  while (ca--) {
    vector<team> teams;
    for (int i = 1; i <= 100; ++i) {
      teams.push_back(team(i));
    }
    int cont, prob, t;
    char L;
    while (getline(cin, s) && s != "") {
      stringstream ss(s);
      ss >> cont >> prob >> t >> L;
      ++teams[cont - 1].subs;
      switch (L) {
        case 'C':
          if (!teams[cont - 1].ind_solve[prob])
            teams[cont - 1].ind_penalty[prob] += t;
          teams[cont - 1].ind_solve[prob] = true;
          break;
        case 'I':
          if (!teams[cont - 1].ind_solve[prob])
            teams[cont - 1].ind_penalty[prob] += 20;
          break;
        default:
          break;
      }
    }

    for (int i = 0; i < 100; ++i) {
      teams[i].calc();
    }
    sort(teams.begin(), teams.end());

    if (first)
      first = false;
    else
      printf("\n");
    for (int i = 0; i < 100 && teams[i].subs > 0; ++i) {
      printf("%d %d %d\n", teams[i].num, teams[i].solved, teams[i].penalty);
    }
  }
  return 0;
}
