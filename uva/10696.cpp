// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10696
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int f91(int n) {
  if (n <= 100)
    return f91(f91(n + 11));
  else
    return n - 10;
}

int main() {
  int n;
  while (GET(n) && n) {
    printf("f91(%d) = %d\n", n, f91(n));
  }
  return 0;
}
