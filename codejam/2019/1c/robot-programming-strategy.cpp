// Author: btjanaka (Bryon Tjanaka)
// Problem: (Google Code Jam) Robot Programming Strategy
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  cin >> ca;
  for (int caa = 1; caa <= ca; ++caa) {
    int a;
    cin >> a;
    vector<string> c(a);
    vector<bool> won(a, false);
    for (int i = 0; i < a; ++i) cin >> c[i];

    string res = "";
    bool chars[128];
    int won_count = 0;
    int prev_won = -1;
    for (int i = 0; won_count < a && won_count != prev_won; ++i) {
      // Reset
      chars['R'] = chars['P'] = chars['S'] = false;

      // Figure out which characters are present
      for (int j = 0; j < a; ++j) {
        if (won[j]) continue;
        char ch = c[j][i % c[j].size()];
        chars[ch] = true;
      }

      // Impossible if all 3 present
      if (chars['R'] && chars['P'] && chars['S']) {
        res = "IMPOSSIBLE";
        break;
      }

      // Can beat
      char tied_ch, beat_ch;
      if (chars['R'] && chars['P']) {
        tied_ch = 'P';
        beat_ch = 'R';
      } else if (chars['R'] && chars['S']) {
        tied_ch = 'R';
        beat_ch = 'S';
      } else if (chars['S'] && chars['P']) {
        tied_ch = 'S';
        beat_ch = 'P';
      } else if (chars['R']) {
        tied_ch = 'P';
        beat_ch = 'R';
      } else if (chars['S']) {
        tied_ch = 'R';
        beat_ch = 'S';
      } else if (chars['P']) {
        tied_ch = 'S';
        beat_ch = 'P';
      }
      res.push_back(tied_ch);

      // Mark certain players as beat
      prev_won = won_count;
      for (int j = 0; j < a; ++j) {
        char ch = c[j][i % c[j].size()];
        if (!won[j] && ch == beat_ch) {
          ++won_count;
          won[j] = true;
        }
      }
    }

    printf("Case #%d: %s\n", caa, res.c_str());
  }
  return 0;
}
