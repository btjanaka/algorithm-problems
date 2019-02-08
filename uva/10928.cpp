// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10928
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  int ca;
  GET(ca);
  char buf[10000];
  while (ca--) {
    int p;
    GET(p);
    getchar();
    int places[p];
    for (int i = 0; i < p; ++i) {
      fgets(buf, 10000, stdin);
      int nei = 0;
      char* token = strtok(buf, " \n");
      while (token != NULL) {
        ++nei;
        token = strtok(NULL, " \n");
      }
      places[i] = nei;
    }

    int mn = *min_element(places, places + p);
    bool first = true;
    for (int i = 0; i < p; ++i) {
      if (places[i] == mn) {
        if (first) {
          first = false;
        } else {
          putchar(' ');
        }
        printf("%d", i + 1);
      }
    }
    printf("\n");
  }
  return 0;
}
