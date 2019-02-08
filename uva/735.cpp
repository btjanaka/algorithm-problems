// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 735
#include <bits/stdc++.h>
using namespace std;

// List all unique darts scores possible in the set
int init_darts(set<int>& darts) {
  darts.insert(0);   // No score
  darts.insert(50);  // Bulls-eye
  for (int i = 1; i <= 20; ++i) {
    for (int j = 1; j <= 3; ++j) {
      darts.insert(i * j);
    }
  }
}

int main() {
  set<int> darts;
  init_darts(darts);
  vector<int> dart_list;
  for (auto d : darts) dart_list.push_back(d);

  int score;
  while (scanf("%d", &score) && score > 0) {
    int c = 0;
    int p = 0;

    // Count combinations
    for (int i = 0; i < dart_list.size(); ++i) {
      for (int j = i; j < dart_list.size(); ++j) {
        for (int k = j; k < dart_list.size(); ++k) {
          if (dart_list[i] + dart_list[j] + dart_list[k] == score) ++c;
        }
      }
    }

    // Count permutations - these can be repeated
    for (int i = 0; i < dart_list.size(); ++i) {
      for (int j = 0; j < dart_list.size(); ++j) {
        for (int k = 0; k < dart_list.size(); ++k) {
          if (dart_list[i] + dart_list[j] + dart_list[k] == score) ++p;
        }
      }
    }

    // Output
    if (p) {
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, c);
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, p);
    } else {
      printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
    }
    printf(
        "**********************************************************************"
        "\n");
  }
  printf("END OF OUTPUT\n");
  return 0;
}
