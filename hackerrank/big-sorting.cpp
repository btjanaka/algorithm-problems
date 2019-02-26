// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) Big Sorting
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  string nums[n];
  for (int i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  sort(nums, nums + n, [](const string& a, const string& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
  });
  for_each(nums, nums + n, [](const string& s) { cout << s << endl; });
  return 0;
}
