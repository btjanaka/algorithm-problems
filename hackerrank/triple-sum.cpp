// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) triple-sum
// Title: Triple Sum
// Link: https://www.hackerrank.com/challenges/triple-sum/problem
// Idea: Sort the arrays and find all unique numbers in them, then go through b
// and use binary search to find how many numbers in a and c are less than each
// entry in b.
// Difficulty: medium
// Tags: binary-search
#include <bits/stdc++.h>
using namespace std;

vector<int> unique(const vector<int>& a) {
  int n = (int)a.size();
  vector<int> res;
  for (int i = 0; i < n; ++i)
    if (i == 0 || a[i] != a[i - 1]) res.push_back(a[i]);
  return res;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int na, nb, nc;
  cin >> na >> nb >> nc;
  vector<int> a(na), b(nb), c(nc);
  for (int i = 0; i < na; ++i) cin >> a[i];
  for (int i = 0; i < nb; ++i) cin >> b[i];
  for (int i = 0; i < nc; ++i) cin >> c[i];

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  a = unique(a);
  b = unique(b);
  c = unique(c);

  long long tot = 0;
  for (int i = 0; i < nb; ++i) {
    int x = b[i];
    long long a_count = upper_bound(a.begin(), a.end(), x) - a.begin();
    long long c_count = upper_bound(c.begin(), c.end(), x) - c.begin();
    tot += a_count * c_count;
  }

  cout << tot << endl;

  return 0;
}
