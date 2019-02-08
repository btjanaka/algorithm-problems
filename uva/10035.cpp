// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10035
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  while (true) {
    int ch;
    stack<int> a, b;
    while ((ch = getchar()) != ' ') {
      a.push(ch - '0');
    }
    while ((ch = getchar()) != '\n' && ch != EOF) {
      b.push(ch - '0');
    }
    if (a.size() == 1 && b.size() == 1 && a.top() == 0 && b.top() == 0) break;

    int res = 0;
    int carry = 0;
    while (!a.empty() || !b.empty()) {
      int cur = (a.empty() ? 0 : a.top()) + (b.empty() ? 0 : b.top()) + carry;
      carry = cur / 10;
      if (cur >= 10) {
        ++res;
      }
      if (!a.empty()) a.pop();
      if (!b.empty()) b.pop();
    }

    if (res == 0) {
      printf("No carry operation.\n");
    } else if (res == 1) {
      printf("1 carry operation.\n");
    } else {
      printf("%d carry operations.\n", res);
    }
  }
  return 0;
}
