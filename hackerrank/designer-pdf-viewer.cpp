// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) designer-pdf-viewer
// Title: Designer PDF Viewer
// Link: https://www.hackerrank.com/challenges/designer-pdf-viewer/problem
// Idea: Find the max height in each block of text.
// Difficulty: easy
// Tags: implementation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
using namespace std;

int main() {
  int h[26];
  for (int i = 0; i < 26; ++i) GET(h[i]);
  getchar();
  string s;
  cin >> s;
  int len = 0;
  int mx_height = 0;
  for (int i = 0; i < s.size(); ++i) {
    ++len;
    mx_height = max(mx_height, h[s[i] - 'a']);
  }
  printf("%d\n", len * mx_height);
  return 0;
}
