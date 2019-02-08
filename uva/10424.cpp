// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10424
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

// Find the single digit from summing digits
int calc_single(int num) {
  int digit_sum = 0;
  for (; num > 0; num /= 10) {
    digit_sum += num % 10;
  }
  if (digit_sum < 10) {
    return digit_sum;
  } else {
    return calc_single(digit_sum);
  }
}

int main() {
  char name1[100];
  char name2[100];
  int len1, len2;
  int tot1, tot2;
  while (fgets(name1, 100, stdin) != NULL && fgets(name2, 100, stdin) != NULL) {
    len1 = strlen(name1);
    len2 = strlen(name2);
    tot1 = 0;
    tot2 = 0;
    for (int i = 0; i < len1; ++i) {
      if (isupper(name1[i])) {
        tot1 += name1[i] - 'A' + 1;
      } else if (islower(name1[i])) {
        tot1 += name1[i] - 'a' + 1;
      }
    }
    for (int i = 0; i < len2; ++i) {
      if (isupper(name2[i])) {
        tot2 += name2[i] - 'A' + 1;
      } else if (islower(name2[i])) {
        tot2 += name2[i] - 'a' + 1;
      }
    }

    tot1 = calc_single(tot1);
    tot2 = calc_single(tot2);

    float res;
    if (tot1 < tot2) {
      res = (float)tot1 / tot2;
    } else {
      res = (float)tot2 / tot1;
    }
    printf("%.2f %%\n", res * 100);
  }
  return 0;
}
