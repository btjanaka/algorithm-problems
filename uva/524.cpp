// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 524
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  {                                               \
    for (int _i = 0; _i < len; ++_i) {            \
      if (_i != len - 1) {                        \
        printf("%d ", arr[_i]);                   \
      } else {                                    \
        printf("%d\n", arr[_i]);                  \
      }                                           \
    }                                             \
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

int nums[20];

// bitset with all primes from 0 to 31 (inclusive)
int primes = 0b10100000100010100010100010101100;

bool is_prime(int n) { return primes & (1 << n); }

// used tells which numbers have been used so far.
void backtrack(int pos, int n, int used) {
  // If we reached the end, print the array
  if (pos == n) {
    if (is_prime(nums[0] + nums[n - 1])) {
      PAI(nums, n);
    }
  }

  // Go through all possible numbers - if a number is not used and makes a prime
  // with the previous number, try it out.
  // Start at 2 because we always know 1 is used.
  for (int i = 2; i <= n; ++i) {
    if (!(used & (1 << i)) && is_prime(nums[pos - 1] + i)) {
      nums[pos] = i;
      backtrack(pos + 1, n, used | (1 << i));
    }
  }
}

int main() {
  int n;
  GET(n);
  for (int i = 1;; ++i) {
    printf("Case %d:\n", i);
    memset(nums, 0, sizeof(int) * 20);
    nums[0] = 1;
    backtrack(1, n, 0b10);

    // Print a line between each test case
    if (GET(n) > 0) {
      PLN;
    } else {
      break;
    }
  }
  return 0;
}
