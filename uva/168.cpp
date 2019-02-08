// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 168
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  char buf[300];
  int k;
  char mino, thes;
  bool lit[128];
  while (scanf("%s", buf) && buf[0] != '#') {
    scanf(" %c %c %d", &mino, &thes, &k);

    // populate graph
    vector<string> graph(128);
    for (char* token = strtok(buf, ":;."); token != NULL;
         token = strtok(NULL, ":;.")) {
      char p = token[0];
      token = strtok(NULL, ":;.");
      graph[p] = token;
    }

    // traverse
    memset(lit, false, sizeof(lit));
    int ki = 0;
    bool first = true;
    while (true) {
      if (first) {
        first = false;
      } else if (ki == 0) {
        printf("%c ", thes);
        lit[thes] = true;
      }
      ki = (ki + 1) % k;

      bool ok = false;
      for (char ch : graph[mino]) {
        if (ch != thes && !lit[ch]) {
          thes = mino;
          mino = ch;
          ok = true;
          break;
        }
      }
      if (!ok) {
        printf("/%c\n", mino);
        break;
      }
    }
  }
  return 0;
}
