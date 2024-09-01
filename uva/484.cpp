// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 484
// Title: The Department of Redundancy Department
// Link:
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&category=0&problem=425&mosmsg=Submission+received+with+ID+29740718
// Idea: Use a map to count the frequency. Use a vector to keep track of the
// order of the input.
// Difficulty: Easy
// Tags:
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vi keys;  // Needed so that we maintain the input order.
  unordered_map<int, int> freq;
  int x;
  while (GET(x) != EOF) {
    if (freq.find(x) == freq.end()) {
      freq[x] = 1;
      keys.push_back(x);
    } else {
      ++freq[x];
    }
  }

  for (const auto& k : keys) {
    printf("%d %d\n", k, freq[k]);
  }

  return 0;
}
