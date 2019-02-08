// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 105
#include <bits/stdc++.h>
using namespace std;

// NOTE: INPUT SIZE IS MUCH BIGGER THAN IN PROBLEM STATEMENT.
// So make the CITY_SIZE much bigger :)
#define CITY_SIZE 1000000
int city[CITY_SIZE];

int main() {
  // Map out city
  int l, h, r;
  while (scanf("%d %d %d", &l, &h, &r) > 0) {
    for (int i = l; i < r; ++i)
      if (h > city[i]) city[i] = h;
  }

  //// Print out the city - fun
  // for(int i = 0; i < 30; ++i) {
  // printf("%2d:", i);
  // for(int j = 0; j < city[i]; ++j) putchar('*');
  // putchar('\n');
  //}

  // Print the results
  int curr_lvl = 0;
  bool first = true;
  for (int i = 0; i < CITY_SIZE; ++i) {
    if (city[i] != curr_lvl) {
      curr_lvl = city[i];
      if (!first)
        putchar(' ');
      else
        first = false;
      printf("%d %d", i, curr_lvl);
    }
  }
  putchar('\n');

  return 0;
}
