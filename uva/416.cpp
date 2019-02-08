// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 416
// Note: The recursion in this one is super easy. The trick is keeping track of
// which lights burned out. A light can't come back on if it already burned out.

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

int digits[10] = {
    0b0111111, 0b0000110, 0b1011011, 0b1001111, 0b1100110,
    0b1101101, 0b1111101, 0b0000111, 0b1111111, 0b1101111,
};

// It's a fail if, at any position, digit has a bit off and input has a bit on.
// Also check that no lights that were burned suddenly came back on - that is
// also a mismatch.
bool match(int digit, int input, int* burned) {
  for (int i = 0; i < 7; ++i) {
    bool digit_on = digit & 1 << i;
    bool input_on = input & 1 << i;
    bool burned_on = *burned & 1 << i;

    // No input lights can come on if they burned out
    if (input_on && burned_on) {
      return false;
    }

    // Add to the burned set if digit is on but input is off
    if (digit_on && !input_on) {
      *burned |= 1 << i;
    }

    // Input cannot be on if digit is off
    if (!digit_on && input_on) {
      return false;
    }
  }
  return true;
}

bool backtrack(int input_i, int n, int num, int burned, int inputs[]) {
  // End case: reached end of inputs
  if (input_i == n) {
    return true;
  }

  // If matched, go to the next number - otherwise, return false
  if (match(digits[num], inputs[input_i], &burned)) {
    return backtrack(input_i + 1, n, num - 1, burned, inputs);
  }
  return false;
}

int main() {
  int n;
  int inputs[10];
  char buf[10];
  while (GET(n) && n) {
    memset(inputs, 0, sizeof(inputs));

    // Input
    for (int i = 0; i < n; ++i) {
      scanf("%s", buf);
      for (int j = 0; j < 7; ++j) {
        if (buf[j] == 'Y') {
          inputs[i] |= 1 << j;
        }
      }
    }

    // Try all possible starts to find a solution have to start at n - 1 because
    // the sequence is n long
    bool found = false;
    for (int i = n - 1; i < 10; ++i) {
      if (backtrack(0, n, i, 0, inputs)) {
        found = true;
        break;
      }
    }

    // Output
    if (found) {
      printf("MATCH\n");
    } else {
      printf("MISMATCH\n");
    }
  }
  return 0;
}
