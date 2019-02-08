// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12250
#include <bits/stdc++.h>

using namespace std;

int main() {
  char buf[100];
  char res[100];

  scanf("%s\n", buf);
  for (int i = 1; strcmp(buf, "#") != 0; ++i) {
    if (strcmp(buf, "HELLO") == 0) {
      strcpy(res, "ENGLISH");
    } else if (strcmp(buf, "HOLA") == 0) {
      strcpy(res, "SPANISH");
    } else if (strcmp(buf, "HALLO") == 0) {
      strcpy(res, "GERMAN");
    } else if (strcmp(buf, "BONJOUR") == 0) {
      strcpy(res, "FRENCH");
    } else if (strcmp(buf, "CIAO") == 0) {
      strcpy(res, "ITALIAN");
    } else if (strcmp(buf, "ZDRAVSTVUJTE") == 0) {
      strcpy(res, "RUSSIAN");
    } else {
      strcpy(res, "UNKNOWN");
    }
    printf("Case %d: %s\n", i, res);
    scanf("%s\n", buf);
  }
  return 0;
}
