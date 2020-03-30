// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) kaprekar-numbers
// Title: Modified Kaprekar Numbers
// Link: https://www.hackerrank.com/challenges/kaprekar-numbers/problem
// Idea: Brute force -- try all possible values from p to q.
// Difficulty: easy
// Tags: math, implementation
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

bool kaprekar(ll i) {
  ll sq = i * i;
  ll left = sq;
  ll right = 0;
  ll place = 1;
  int d = 0;
  for (sq; sq > 0; ++d, sq /= 10)
    ;
  for (int j = 0; j < (d / 2) + (d % 2); ++j) {
    right = right + (left % 10) * place;
    place *= 10;
    left /= 10;
  }
  return left + right == i;
}

int main() {
  ll p, q;
  scanf("%lld %lld", &p, &q);
  bool first = true;
  for (ll i = p; i <= q; ++i) {
    if (kaprekar(i)) {
      if (first) {
        first = false;
      } else {
        putchar(' ');
      }
      printf("%lld", i);
    }
  }
  if (first) printf("INVALID RANGE");
  putchar('\n');
  return 0;
}
