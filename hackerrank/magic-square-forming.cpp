// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) magic-square-forming
// Title: Forming a Magic Square
// Link: https://www.hackerrank.com/challenges/magic-square-forming/problem
// Idea: Find all possible magic squares and see which one takes the least cost
// to convert to.
// Difficulty: medium
// Tags: implementation, brute-force
#include <bits/stdc++.h>
using namespace std;
#define GET(x) scanf("%d", &x)

vector<vector<int>> indices = {
    {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6},
    {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6},
};

int cost(vector<int>& sq, vector<int>& nums) {
  int res = 0;
  for (int i = 0; i < 9; ++i) {
    res += abs(sq[i] - nums[i]);
  }
  return res;
}

bool magic(vector<int>& n) {
  int k = n[0] + n[1] + n[2];
  for (int i = 1; i < indices.size(); ++i) {
    int s = n[indices[i][0]] + n[indices[i][1]] + n[indices[i][2]];
    if (s != k) return false;
  }
  return true;
}

int main() {
  vector<int> sq;
  for (int i = 0; i < 9; ++i) {
    int x;
    GET(x);
    sq.push_back(x);
  }
  vector<int> nums(9);
  iota(nums.begin(), nums.end(), 1);
  int min_cost = INT_MAX;
  do {
    if (magic(nums)) {
      min_cost = min(min_cost, cost(sq, nums));
    }
  } while (next_permutation(nums.begin(), nums.end()));
  printf("%d\n", min_cost);
  return 0;
}
