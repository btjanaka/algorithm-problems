// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) musicalchairs
// Title: Musical Chairs
// Link: https://open.kattis.com/problems/musicalchairs
// Idea: Brute force - n is small enough that we can just remove from the list
// in O(n) time.
// Difficulty: easy
// Tags: math, brute-force
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> k;  // {original, fav num}
  for (int i = 0; i < n; ++i) {
    int fav;
    cin >> fav;
    k.push_back({i, fav});
  }

  int cur = 0;
  for (int i = 1; i < n; ++i) {
    int remove = (cur + k[cur].second - 1) % k.size();
    cur = remove % (k.size() - 1);
    k.erase(k.begin() + remove, k.begin() + remove + 1);
  }

  cout << k[0].first + 1 << endl;

  return 0;
}
