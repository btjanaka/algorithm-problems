// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) angry-professor
// Title: Angry Professor
// Link: https://www.hackerrank.com/challenges/angry-professor/problem
// Idea: Simply count the number of ontime students.
// Difficulty: easy
// Tags: implementation
#include <bits/stdc++.h>
using namespace std;
#define GET(x) scanf("%d", &(x))

int main() {
  int ca;
  GET(ca);
  while (ca--) {
    int n, k;
    GET(n);
    GET(k);
    int ontime = 0;
    int x;
    for (int i = 0; i < n; ++i) {
      GET(x);
      ontime += x <= 0;
    }
    printf(ontime < k ? "YES" : "NO");
    printf("\n");
  }
  return 0;
}
