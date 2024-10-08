// Author: btjanaka (Bryon Tjanaka)
// Problem: (CodeForces) 952a
// Title: Quirky Quantifiers
// Link: http://codeforces.com/contest/952/problem/A
// Idea: Output the number modulo 2.
// Difficulty: easy
// Tags: math
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  int x;
  GET(x);
  printf("%d\n", x % 2);
  return 0;
}
