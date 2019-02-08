// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10706
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

// Find the length of the sequence a_k.
long long len_a(int k) {
  long long digits = 0;
  for (int i = 1; i <= k; ++i) {
    long long i_dig;
    int j = i;
    for (i_dig = 0; j > 0; j /= 10) ++i_dig;
    digits += i_dig * (k - i + 1);
  }
  return digits;
}

int main() {
  int t;
  GET(t);
  while (t--) {
    int tgt;
    int digit_ans;
    GET(tgt);

    // Search for the k that generates a sequence of length <= tgt, i.e. find k
    // such that a_k <= tgt
    int lo = 0, hi = 33000, mid = 0, final_k = 0;
    while ((hi - lo) > 1) {
      mid = (lo + hi) / 2;
      long long len = len_a(mid);
      // printf("%d %d %d %d %lld\n", lo, mid, hi, tgt, len);
      if (len == tgt) {
        final_k = mid;
        break;
      } else if (len < tgt) {
        lo = mid;
        final_k = mid;
      } else {
        hi = mid;
      }
    }

    // Find the exact digit
    long long pos = len_a(final_k);
    // printf("*tgt: %d k: %d pos: %d\n", tgt, final_k, pos);
    if (pos == tgt) {
      digit_ans = final_k % 10;
    } else {
      // Iterate through numbers until adequate digits are reached
      for (int j = 1; j <= final_k + 1; ++j) {
        long long j_dig;
        int l = j;
        for (j_dig = 0; l > 0; l /= 10) ++j_dig;

        // If we found the correct number of digits, find out what digit in j we
        // need to get to, and get to it.
        if (pos + j_dig >= tgt) {
          int rem = pos + j_dig - tgt;
          for (int h = 0; h < rem; ++h) {
            j /= 10;
          }
          digit_ans = j % 10;
          break;
        } else {
          pos += j_dig;
        }
      }
    }
    printf("%d\n", digit_ans);
  }
  return 0;
}
