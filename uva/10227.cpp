// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10227
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  GET(ca);
  char buf[50];
  int p, t;
  bool first = true;
  while (ca--) {
    GET(p);
    GET(t);
    vector<set<int>> saw(p);
    getchar();
    int i, j;
    while (fgets(buf, 50, stdin) && buf[0] != '\n') {
      sscanf(buf, "%d %d", &i, &j);
      --i;
      --j;
      saw[i].insert(j);
    }
    set<set<int>> opi;
    for (int i = 0; i < p; ++i) {
      opi.insert(saw[i]);
    }
    if (first)
      first = false;
    else
      putchar('\n');
    printf("%d\n", (int)opi.size());
  }
  return 0;
}
