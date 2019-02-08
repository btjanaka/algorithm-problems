// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 119
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

// Input is small enough that we can use linear searches to add amounts for a
// given name.
void add_worth(char names[15][15], int worth[15], int n, char* rcv, int amt) {
  for (int i = 0; i < n; ++i) {
    if (strcmp(rcv, names[i]) == 0) {
      worth[i] += amt;
      return;
    }
  }
}

int main() {
  int n;
  char names[15][15];
  int worth[15];
  char person[15];
  char rcv[15];
  if (GET(n) > 0) {
    while (true) {
      // Get names
      for (int i = 0; i < n; ++i) {
        scanf("%s", names[i]);
      }

      // Simulate gifts
      int amt;
      int ppl;
      memset(worth, 0, sizeof(worth));
      for (int i = 0; i < n; ++i) {
        scanf("%s %d %d", person, &amt, &ppl);

        if (ppl == 0) continue;

        // Add amount for this person
        add_worth(names, worth, n, person, amt % ppl - amt);

        // Add their gifts to everyone else
        for (int j = 0; j < ppl; ++j) {
          scanf("%s", rcv);
          add_worth(names, worth, n, rcv, amt / ppl);
        }
      }

      // Print results
      for (int i = 0; i < n; ++i) {
        printf("%s %d\n", names[i], worth[i]);
      }

      // Find out if there are anymore inputs
      if (GET(n) > 0) {
        PLN;
      } else {
        break;
      }
    }
  }
  return 0;
}
