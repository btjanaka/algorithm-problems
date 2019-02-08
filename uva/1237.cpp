// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 1237
#include <bits/stdc++.h>
using namespace std;

char makers[10010][20];
int l[10010];
int h[10010];

int main() {
  int c;
  scanf("%d", &c);
  while (c--) {
    // Input
    int d;
    scanf("%d", &d);
    for (int i = 0; i < d; ++i) scanf("%s %d %d", makers[i], &l[i], &h[i]);
    int q;
    scanf("%d", &q);

    // Queries
    for (int i = 0; i < q; ++i) {
      int p;
      scanf("%d", &p);
      int res = -1;
      for (int j = 0; j < d; ++j) {
        if (l[j] <= p && p <= h[j]) {
          if (res == -1) {
            res = j;
          } else {
            goto error;
          }
        }
      }
      // Output
      if (res == -1) goto error;
      printf("%s\n", makers[res]);
      continue;
    error:
      printf("UNDETERMINED\n");
    }
    if (c) printf("\n");
  }
  return 0;
}
