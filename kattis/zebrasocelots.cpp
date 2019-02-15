// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) zebrasocelots
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int n;
char zo[100];

int main() {
  GET(n);
  for (int i = 0; i < n; ++i) {
    scanf(" %c", zo + i);
  }
  long long res = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (zo[i] == 'O') {
      res += (1L << (n - i - 1));
    }
  }
  printf("%lld\n", res);
  return 0;
}
