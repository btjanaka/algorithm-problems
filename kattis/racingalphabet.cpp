// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) racingalphabet
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int n;
  GET(n);
  getchar();

  unordered_map<char, int> letters;
  for (char ch = 'A'; ch <= 'Z'; ++ch) {
    letters[ch] = ch - 'A';
  }
  letters[' '] = 26;
  letters['\''] = 27;

  while (n--) {
    char ch = getchar();
    int pos = letters[ch];

    double res = 1.0;
    while ((ch = getchar()) != '\n') {
      int next_pos = letters[ch];
      int d1 = next_pos >= pos ? next_pos - pos : pos - next_pos;
      int d2 = 28 - d1;

      res += (double)min(d1, d2) / 28.0 * (4.0 * M_PI) + 1.0;

      pos = next_pos;
    }
    printf("%.8lf\n", res);
  }
  return 0;
}
