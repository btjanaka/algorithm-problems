// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11742
#include <bits/stdc++.h>
using namespace std;

int reqs[25][3];

bool satisfies_req(int i, int n, int p[]) {
  int p1, p2;
  for (int j = 0; j < n; ++j) {
    if (p[j] == reqs[i][0]) p1 = j;
    if (p[j] == reqs[i][1]) p2 = j;
  }
  if (reqs[i][2] > 0) {
    return abs(p2 - p1) <= reqs[i][2];
  } else {
    return abs(p2 - p1) >= -reqs[i][2];
  }
}

int main() {
  int n, m;
  scanf("%d %d\n", &n, &m);
  while (n > 0) {
    for (int i = 0; i < m; ++i)
      scanf("%d %d %d\n", &reqs[i][0], &reqs[i][1], &reqs[i][2]);

    int p[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int counter = 0;
    do {
      bool satisfies_all = true;
      for (int i = 0; i < m; ++i) satisfies_all &= satisfies_req(i, n, p);
      if (satisfies_all) ++counter;
    } while (next_permutation(p, p + n));
    printf("%d\n", counter);

    scanf("%d %d\n", &n, &m);
  }
  return 0;
}
