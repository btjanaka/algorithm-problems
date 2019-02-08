// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11876
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d", arr[_i]);                    \
      }                                           \
    }                                             \
    putchar('\n');                                \
  }
#define PBS(n, len) /*Print a bitset*/ \
  {                                    \
    for (int _i = 0; _i < len; ++_i) { \
      putchar(n % 2 + '0');            \
      n /= 2;                          \
    }                                  \
    putchar('\n');                     \
  }
#define GET(x) scanf("%d", &x)
#define PLN putchar('\n')
#define INF 2147483647
typedef long long ll;
using namespace std;

int seq[500000];
int seq_i;

// Find number of divisors of a number
int nod(int num) {
  int res = 0;
  for (int i = 1; i <= (int)sqrt(num); ++i) {
    if (num % i == 0) {
      if (i * i != num) {
        res += 2;
      } else {
        res++;
      }
    }
  }
  return res;
}

// Precalc the seq
void gen_seq() {
  seq_i = 0;
  for (int i = 1; i <= 1000000; i += nod(i)) {
    seq[seq_i++] = i;
  }
}

int main() {
  int t;
  int a, b;
  GET(t);
  gen_seq();
  for (int ca = 1; ca <= t; ++ca) {
    scanf("%d %d", &a, &b);
    printf("Case %d: %ld\n", ca,
           upper_bound(seq, seq + seq_i, b) - lower_bound(seq, seq + seq_i, a));
  }
  return 0;
}
