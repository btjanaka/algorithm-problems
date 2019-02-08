// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 732
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

void backtrack(char ans[], int ind, int n, int i_s, int o_s, stack<char>& cur,
               const string& a, const string& b) {
  if (ind == n) {
    for (int i = 0; i < n; ++i) {
      printf("%c%c", ans[i], i == n - 1 ? '\n' : ' ');
    }
    return;
  }

  if (i_s < n / 2) {
    ans[ind] = 'i';
    cur.push(a[i_s]);
    backtrack(ans, ind + 1, n, i_s + 1, o_s, cur, a, b);
    cur.pop();
  }

  if (o_s < i_s && !cur.empty() && cur.top() == b[o_s]) {
    ans[ind] = 'o';
    char save = cur.top();
    cur.pop();
    backtrack(ans, ind + 1, n, i_s, o_s + 1, cur, a, b);
    cur.push(save);
  }
}

int main() {
  string a, b;
  while (cin >> a >> b) {
    char ans[a.size() * 2];
    printf("[\n");
    stack<char> cur;
    if (a.size() == b.size()) backtrack(ans, 0, a.size() * 2, 0, 0, cur, a, b);
    printf("]\n");
  }
  return 0;
}
