// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12348
// Note: This problem passes all cases on uDebug, but it submits as Wrong Answer
// still. Trying solutions from other people on the web, even ones that claim to
// be accepted, also yields errors of some sort.

#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
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

// Tells which members are in each set
int sets[120];

int main() {
  int k;
  GET(k);
  int n, m;
  char buf[20];
  while (k--) {
    // Reset
    memset(sets, 0, sizeof(sets));

    // Obtain inputs
    GET(n);
    GET(m);
    getchar();
    for (int i = 0; i < m; ++i) {
      fgets(buf, 20, stdin);
      char* token = strtok(buf, " \n");
      while (token != NULL) {
        int x = atoi(token) - 1;  // 0-indexed
        sets[i] |= 1 << x;
        token = strtok(NULL, " \n");
      }
    }

    // Debug
    // for (int i = 0; i < m; ++i) PBS(sets[i], n);

    // Analyze all possible colorings
    int matched = false;
    for (int i = 0; i < (1 << n); ++i) {
      int this_match = true;
      for (int j = 0; j < m; ++j) {
        // If i & set[j] is 0, all the bits corresponding to elements in sets[j]
        // are off. If it is sets[j], all the bits are on. Neither scenario is
        // desirable, as we want 1 off and 1 on in every set.
        bool one_different = (i & sets[j]) != 0 && (i & sets[j]) != sets[j];

        // Alternatively, the set can just have only one member, since that
        // satisfies the condition that "at least one member of S is assigned a
        // different from the others". This check is done by checking if sets[j]
        // is a power of 2.
        bool single_member = (sets[j] & (sets[j] - 1)) == 0;

        this_match &= one_different || single_member;
      }
      if (this_match) {
        matched = true;
        break;
      }
    }

    if (matched) {
      putchar('Y');
    } else {
      putchar('N');
    }
  }
  return 0;
}
