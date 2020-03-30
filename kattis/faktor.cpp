// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) faktor
// Title: Faktor
// Link: https://open.kattis.com/problems/faktor
// Idea:
// Difficulty: easy
// Tags: math
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
typedef long long ll;
using namespace std;

int main() {
  int a, i;
  GET(a);
  GET(i);
  printf("%d\n", a * (i - 1) + 1);
  return 0;
}
