// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12532
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int a[100100];

struct FenwickTree {
  vector<int> ft;
  FenwickTree(int n) { ft.assign(n + 1, 0); }
  int lsone(int i) { return i & (-i); }
  int rsq(int b) {
    int sum = 0;
    for (; b; b -= lsone(b)) sum += ft[b];
    return sum;
  }
  int rsq(int a, int b) { return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
  void adjust(int k, int v) {
    for (; k < (int)ft.size(); k += lsone(k)) ft[k] += v;
  }
};

int main() {
  // store number of negatives and 0's instead of actual products
  int n, k;
  while (GET(n) > 0) {
    FenwickTree neg(n), zero(n);
    GET(k);
    for (int i = 1; i <= n; ++i) {
      GET(a[i]);
      if (a[i] < 0) {
        neg.adjust(i, 1);
      } else if (a[i] == 0) {
        zero.adjust(i, 1);
      }
    }

    char ch;
    int i, j;
    while (k--) {
      scanf(" %c %d %d", &ch, &i, &j);
      switch (ch) {
        case 'C':
          if (j > 0) {
            if (a[i] < 0) {
              neg.adjust(i, -1);
            } else if (a[i] == 0) {
              zero.adjust(i, -1);
            }
          } else if (j < 0) {
            if (a[i] == 0) {
              zero.adjust(i, -1);
            }
            if (a[i] >= 0) {
              neg.adjust(i, 1);
            }
          } else {
            if (a[i] < 0) {
              neg.adjust(i, -1);
            }
            if (a[i] != 0) {
              zero.adjust(i, 1);
            }
          }
          a[i] = j;
          break;
        case 'P':
          int zeros = zero.rsq(i, j);
          int negs = neg.rsq(i, j);
          if (zeros > 0) {
            putchar('0');
          } else if (negs % 2 == 0) {
            putchar('+');
          } else {
            putchar('-');
          }
          break;
      }
    }
    putchar('\n');
  }
  return 0;
}
