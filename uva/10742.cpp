// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10742
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

bool is_prime[1000000];  // All init to false
int primes[500000];
int num_primes;

// Use sieve to generate primes
void generate_primes() {
  memset(is_prime, true, sizeof(is_prime));
  num_primes = 0;
  for (int i = 2; i < 1000000; ++i) {
    if (is_prime[i]) {
      primes[num_primes++] = i;
      for (int j = 2 * i; j < 1000000; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
  int n;
  generate_primes();
  for (int ca = 1; GET(n) && n; ++ca) {
    int tot = 0;
    for (int i = 0; primes[i] <= n; ++i) {
      // Find the location of the first number that would not be able to add up
      // with the current one - then count the numbers between here and there.
      int* loc =
          upper_bound(primes + i + 1, primes + num_primes, n - primes[i]);
      tot += loc - (primes + i + 1);
    }
    printf("Case %d: %d\n", ca, tot);
  }
  return 0;
}
