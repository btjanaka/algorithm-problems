// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 300
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

const char* month_names[19] = {"pop", "no",     "zip",   "zotz",   "tzec",
                               "xul", "yoxkin", "mol",   "chen",   "yax",
                               "zac", "ceh",    "mac",   "kankin", "muan",
                               "pax", "koyab",  "cumhu", "uayet"};
const char* tmonths[20] = {"imix",  "ik",    "akbal", "kan",   "chicchan",
                           "cimi",  "manik", "lamat", "muluk", "ok",
                           "chuen", "eb",    "ben",   "ix",    "mem",
                           "cib",   "caban", "eznab", "canac", "ahau"};

int main() {
  unordered_map<string, int> months;
  for (int i = 0; i < 19; ++i) {
    months[month_names[i]] = i;
  }

  int ca;
  GET(ca);
  printf("%d\n", ca);

  char buf[30];

  while (ca--) {
    int d, yr;
    scanf("%d. %s %d", &d, buf, &yr);
    string ms(buf);
    int m = months[ms];

    int totd = yr * 365 + m * 20 + d;

    int resyr = totd / 260;
    totd %= 260;
    int resm = totd % 20;
    int resd = totd % 13;
    printf("%d %s %d\n", resd + 1, tmonths[resm], resyr);
  }

  return 0;
}
