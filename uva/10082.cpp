// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10082
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  unordered_map<char, char> m;
  string keys[4] = {"`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'",
                    "ZXCVBNM,./"};
  for (int i = 0; i < 4; ++i) {
    for (int j = 1; j < keys[i].size(); ++j) {
      m[keys[i][j]] = keys[i][j - 1];
    }
  }
  m[' '] = ' ';

  string s;
  while (getline(cin, s)) {
    for (char ch : s) {
      putchar(m[ch]);
    }
    putchar('\n');
  }
  return 0;
}
