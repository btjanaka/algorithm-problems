// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10276
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

int nums[55];

bool is_square(int x) {
  int rt = (int)sqrt(x);
  return rt * rt == x;
}

// Find the maximum number we can count up to on the pegs.
int backtrack(int curr, int n) {
  int mx = curr - 1;
  int i;
  bool found = false;  // If the ball is found to match one of the nums.
  for (i = 0; nums[i] != 0 && i < n; ++i) {
    if (is_square(nums[i] + curr)) {
      found = true;
      int tmp = nums[i];
      nums[i] = curr;
      mx = max(backtrack(curr + 1, n), mx);
      nums[i] = tmp;
    }
  }

  // Last case to fill up empty slots.
  // Don't fill up an empty slot if we already found a place where the ball
  // matches - this creates a lot of extra slots.
  if (i < n && !found) {
    int tmp = nums[i];
    nums[i] = curr;
    mx = max(backtrack(curr + 1, n), mx);
    nums[i] = tmp;
  }

  return mx;
}

int main() {
  int t;
  GET(t);
  FOR(i, 0, t) {
    memset(nums, 0, sizeof(int) * 50);
    int n;
    GET(n);
    printf("%d\n", backtrack(1, n));
  }
  return 0;
}
