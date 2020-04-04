// Author: btjanaka (Bryon Tjanaka)
// Problem: (CodeJam) 2017-qual-oversized-pancake-flipper
// Title: Oversized Pancake Flipper
// Link: https://code.google.com/codejam/contest/dashboard?c=3264486
// Idea: See comments.
// Difficulty: easy
// Tags: ad-hoc
#include <bits/stdc++.h>
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define GET(x) scanf("%d", &x)
using namespace std;

char s[1010];
bool p[1010];

int main() {
  int t;
  GET(t);
  FORe(ca, 1, t) {
    // Iterate through pancakes and try to "herd" all the false's to the left by
    // flipping whenever we see a false. If the array does not end up with all
    // false's in the k positions at the end, there is no solution. false
    // represents sad pancake, true is happy.
    int k;
    scanf("%s %d", s, &k);
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
      if (s[i] == '+') {
        p[i] = true;
      } else {
        p[i] = false;
      }
    }

    int flips = 0;
    // No need to do the process if they are already all happy
    // Herding
    for (int i = 0; i < len - k; ++i) {
      if (!p[i]) {
        ++flips;
        for (int j = i; j < i + k; ++j) {
          p[j] = !p[j];
        }
      }
    }
    // Final check
    bool ok = true;
    bool all_happy = true;
    for (int i = len - k; i < len; ++i) {
      all_happy &= p[i];
      if (p[i]) {
        ok = false;
      }
    }
    if (ok) ++flips;
    if (all_happy) ok = true;

    // output
    printf("Case #%d: ", ca);
    if (ok) {
      printf("%d\n", flips);
    } else {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}
