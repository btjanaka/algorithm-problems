// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 102
#include <bits/stdc++.h>
using namespace std;

int bins[3][3];  // Brown, green, clear

int take_bins() {
  int tot = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      tot += scanf("%d", &bins[i][j]);
    }
  }
  return tot;
}

int main() {
  while (take_bins() > 0) {
    long long tot = 1L << 33;
    long long tmp = 0;
    char res[10];

    // GCB
    tmp = bins[1][1] + bins[2][1] + bins[0][2] + bins[2][2] + bins[0][0] +
          bins[1][0];
    if (tmp <= tot) {
      tot = tmp;
      strcpy(res, "GCB");
    }

    // GBC
    tmp = bins[1][1] + bins[2][1] + bins[0][0] + bins[2][0] + bins[0][2] +
          bins[1][2];
    if (tmp <= tot) {
      tot = tmp;
      strcpy(res, "GBC");
    }

    // CGB
    tmp = bins[1][2] + bins[2][2] + bins[0][1] + bins[2][1] + bins[0][0] +
          bins[1][0];
    if (tmp <= tot) {
      tot = tmp;
      strcpy(res, "CGB");
    }

    // CBG
    tmp = bins[1][2] + bins[2][2] + bins[0][0] + bins[2][0] + bins[0][1] +
          bins[1][1];
    if (tmp <= tot) {
      tot = tmp;
      strcpy(res, "CBG");
    }

    // BGC
    tmp = bins[1][0] + bins[2][0] + bins[0][1] + bins[2][1] + bins[0][2] +
          bins[1][2];
    if (tmp <= tot) {
      tot = tmp;
      strcpy(res, "BGC");
    }

    // BCG
    tmp = bins[1][0] + bins[2][0] + bins[0][2] + bins[2][2] + bins[0][1] +
          bins[1][1];
    if (tmp <= tot) {
      tot = tmp;
      strcpy(res, "BCG");
    }

    printf("%s %lld\n", res, tot);
  }
  return 0;
}
