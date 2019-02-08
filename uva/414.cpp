// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 414
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int n;
  while (GET(n) && n) {
    getchar();
    int count[20];
    char ch;
    for (int i = 0; i < n; ++i) {
      count[i] = 0;
      while ((ch = getchar()) && ch != '\n') count[i] += ch == 'X';
    }
    int mx = *max_element(count, count + n);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
      tot += mx - count[i];
    }
    printf("%d\n", tot);
  }
  return 0;
}
