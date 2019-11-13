// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) bossbattle
// Title: Boss Battle
// Link: https://open.kattis.com/problems/bossbattle
// Idea: Subtract 2 (usually).
// Difficulty: easy
// Tags: easy
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
typedef long long ll;
using namespace std;

int main() {
  int n;
  GET(n);
  if (n == 1 || n == 2 || n == 3) {
    printf("1\n");
  } else {
    printf("%d\n", n - 2);
  }
  return 0;
}
