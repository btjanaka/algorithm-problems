// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 101
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

// Positions represented as pile, position in pile
pair<int, int> find_block(vector<vector<int>>& piles, int b) {
  int pile;
  int pos_in_pile;
  for (pile = 0; pile < piles.size(); ++pile) {
    for (pos_in_pile = 0; pos_in_pile < piles[pile].size(); ++pos_in_pile) {
      if (piles[pile][pos_in_pile] == b) return {pile, pos_in_pile};
    }
  }
  return {-1, -1};
}

// Move top blocks back to original pos
void return_top_blocks(pair<int, int> b, vector<vector<int>>& piles) {
  int rm_num = piles[b.first].size() - b.second - 1;
  for (int i = 0; i < rm_num; ++i) {
    int top = piles[b.first].back();
    piles[top].insert(piles[top].begin(), top);
    piles[b.first].pop_back();
  }
}

int main() {
  string cmd1, cmd2;
  int a, b;
  int n;
  cin >> n;
  vector<vector<int>> piles(n, vector<int>());

  // Initial pos
  for (int i = 0; i < n; ++i) {
    piles[i].push_back(i);
  }

  while (cin >> cmd1 && cmd1 != "quit") {
    cin >> a >> cmd2 >> b;
    if (a == b) continue;
    pair<int, int> a_posx = find_block(piles, a);
    pair<int, int> b_posx = find_block(piles, b);
    if (a_posx.first == b_posx.first) continue;
    if (cmd1 == "move" && cmd2 == "onto") {
      return_top_blocks(find_block(piles, a), piles);
      return_top_blocks(find_block(piles, b), piles);
      pair<int, int> a_pos = find_block(piles, a);
      pair<int, int> b_pos = find_block(piles, b);
      piles[a_pos.first].pop_back();
      piles[b_pos.first].push_back(a);
    } else if (cmd1 == "move" && cmd2 == "over") {
      return_top_blocks(find_block(piles, a), piles);
      pair<int, int> a_pos = find_block(piles, a);
      pair<int, int> b_pos = find_block(piles, b);
      piles[a_pos.first].pop_back();
      piles[b_pos.first].push_back(a);
    } else if (cmd1 == "pile" && cmd2 == "onto") {
      return_top_blocks(find_block(piles, b), piles);
      pair<int, int> a_pos = find_block(piles, a);
      pair<int, int> b_pos = find_block(piles, b);
      for (int i = a_pos.second; i < piles[a_pos.first].size(); ++i) {
        piles[b_pos.first].push_back(piles[a_pos.first][i]);
      }
      piles[a_pos.first].erase(piles[a_pos.first].begin() + a_pos.second,
                               piles[a_pos.first].end());
    } else if (cmd1 == "pile" && cmd2 == "over") {
      pair<int, int> a_pos = find_block(piles, a);
      pair<int, int> b_pos = find_block(piles, b);
      for (int i = a_pos.second; i < piles[a_pos.first].size(); ++i) {
        piles[b_pos.first].push_back(piles[a_pos.first][i]);
      }
      piles[a_pos.first].erase(piles[a_pos.first].begin() + a_pos.second,
                               piles[a_pos.first].end());
    }
  }

  for (int i = 0; i < piles.size(); ++i) {
    printf("%d:", i);
    for_each(piles[i].begin(), piles[i].end(), [](int j) { printf(" %d", j); });
    printf("\n");
  }

  return 0;
}
