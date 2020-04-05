// Author: btjanaka (Bryon Tjanaka)
// Problem: (Google Kickstart) 2019a-training
// Title: Training
// Link:
// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050e01/00000000000698d6
// Idea:
// Difficulty: medium
// Tags: arrays
#include <bits/stdc++.h>
using namespace std;
#define GET(x) scanf("%d", &x)

int s[100100];

int main() {
  int ca;
  GET(ca);
  for (int caa = 1; caa <= ca; ++caa) {
    int n, p;
    GET(n);
    GET(p);
    for (int i = 0; i < n; ++i) GET(s[i]);

    sort(s, s + n);

    // create an initial count
    long long cur_amt = 0;
    for (int i = 0; i < p; ++i) {
      cur_amt += s[p - 1] - s[i];
    }
    long long mn_amt = cur_amt;

    // go through rest of array and keep adding the appropriate amt
    // and subtracting the previous
    for (int i = p; i < n; ++i) {
      long long new_amt = cur_amt;
      new_amt -= s[i - 1] - s[i - p];
      new_amt += (long long)(p - 1) * (long long)(s[i] - s[i - 1]);
      mn_amt = min(new_amt, mn_amt);
      cur_amt = new_amt;
    }

    printf("Case #%d: %lld\n", caa, mn_amt);
  }
}
