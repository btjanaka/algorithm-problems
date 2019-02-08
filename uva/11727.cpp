// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11727
#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    vector<int> nums;
    for (int j = 0; j < 3; ++j) {
      int x;
      cin >> x;
      nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    printf("Case %d: %d\n", i, nums[1]);
  }
  return 0;
}
