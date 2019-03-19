// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) designer-pdf-viewer
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int h[26];
  for (int i = 0; i < 26; ++i) GET(h[i]);
  getchar();
  string s;
  cin >> s;
  int len = 0;
  int mx_height = 0;
  for (int i = 0; i < s.size(); ++i) {
    ++len;
    mx_height = max(mx_height, h[s[i] - 'a']);
  }
  printf("%d\n", len * mx_height);
  return 0;
}
