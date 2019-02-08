// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10785
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

char vowels[110];
char cons[110];

int main() {
  // generate source letters
  int d = 0;
  int v[5] = {'A', 'U', 'E', 'O', 'I'};
  int c[21] = {'J', 'S', 'B', 'K', 'T', 'C', 'L', 'D', 'M', 'V', 'N',
               'W', 'F', 'X', 'G', 'P', 'Y', 'H', 'Q', 'Z', 'R'};
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 21; ++j) {
      vowels[d++] = v[i];
    }
  }
  vowels[d] = 0;
  d = 0;
  for (int i = 0; i < 21; ++i) {
    for (int j = 0; j < 5; ++j) {
      cons[d++] = c[i];
    }
  }
  cons[d] = 0;

  // printf("%s\n%s\n", vowels, cons);

  // generate sequence
  int n;
  int ca;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    printf("Case %d: ", caa);

    GET(n);
    int vi = 0;
    int ci = 0;
    priority_queue<char, vector<int>, greater<int>> xv, xc;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        xv.push(vowels[vi++]);
      } else {
        xc.push(cons[ci++]);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        putchar(xv.top());
        xv.pop();
      } else {
        putchar(xc.top());
        xc.pop();
      }
    }
    putchar('\n');
  }
  return 0;
}
