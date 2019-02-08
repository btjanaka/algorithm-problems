// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 1062
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  char buf[1010];
  for (int ca = 1; scanf("%s", buf) && strcmp(buf, "end") != 0; ++ca) {
    bool seen[26];
    memset(seen, false, sizeof(seen));
    int len = strlen(buf);

    // Strategy: either one stack per character or have a stack going from low
    // to high letter (from top to bottom).
    unordered_set<char>
        tops;  // Tops of stacks; for each character in buf, we check to see if
               // we can maintain a current top, or if we can find the next
               // nearest top to put it on top of, or if we have to insert a new
               // top altogether. This greedily minimizes the number of stacks.
    for (int i = 0; i < len; ++i) {
      seen[buf[i] - 'A'] = true;

      // Find the next character that can be inserted
      auto itr = tops.end();
      for (char ch = buf[i]; ch <= 'Z'; ++ch) {
        if (tops.find(ch) != tops.end()) {
          itr = tops.find(ch);
          break;
        }
      }
      if (itr != tops.end()) {
        tops.erase(itr);
        tops.insert(buf[i]);
      } else {
        tops.insert(buf[i]);
      }
    }
    int chars = accumulate(seen, seen + 26, 0);
    int stacks = tops.size();

    printf("Case %d: %d\n", ca, min(chars, stacks));
  }
  return 0;
}
