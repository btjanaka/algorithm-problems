#include <bits/stdc++.h>
using namespace std;

int tot;
int n;

void backtrack(int c, int rw, int ld, int rd) {
  if (c == n) {
    ++tot;
    return;
  }
  for (int r = 0; r < n; ++r) {
    int p = 1 << r;
    if (!(p & rw) && !(p & ld) && !(p & rd)) {
      backtrack(c + 1, rw | p, (ld | p) << 1, (rd | p) >> 1);
    }
  }
}

int main() {
  while (scanf("%d", &n) > 0) {
    tot = 0;
    backtrack(0, 0, 0, 0);
    printf("%d solutions\n", tot);
  }
  return 0;
}
