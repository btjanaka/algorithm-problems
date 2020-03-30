// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) max-array-sum
// Title: Max Array Sum
// Link: https://www.hackerrank.com/challenges/max-array-sum/problem
// Idea:
// Difficulty: medium
// Tags: dynamic-programming, arrays
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int n;
  while (GET(n) > 0) {
    vector<int> a(n);
    for (int i = 0; i < n; ++i) GET(a[i]);

    vector<int> mx(n);
    mx[0] = max(0, a[0]);
    if (n >= 2) {
      mx[1] = max(0, max(a[0], a[1]));
      for (int i = 2; i < n; ++i) {
        int m1 = max(mx[i - 2] + a[i], mx[i - 1]);
        int m2 = max(mx[i - 2], 0);
        mx[i] = max(m1, m2);
      }
    }

    printf("%d\n", mx[n - 1]);
  }
  return 0;
}
