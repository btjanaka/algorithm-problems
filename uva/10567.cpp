// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10567
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

int main() {
  // Load positions of each letter into vectors
  vector<int> letters[128];
  char ch;
  int pos = 0;
  while ((ch = getchar()) != '\n') {
    letters[(int)ch].push_back(pos);
    ++pos;
  }

  // Take queries
  int q;
  GET(q);
  char query[110];
  while (q--) {
    scanf("%s", query);
    int pos = -1;
    int begin, end;
    bool match = true;
    int next;
    for (int i = 0; query[i] != 0; ++i) {
      // Search for position of next letter in sequence
      next = query[i];
      auto next_pos =
          lower_bound(letters[next].begin(), letters[next].end(), pos + 1);
      if (next_pos == letters[next].end()) {
        match = false;
        break;
      }
      pos = *next_pos;

      // Set begin and end
      if (i == 0) {
        begin = pos;
      } else if (query[i + 1] == 0) {
        end = pos;
      }
    }
    if (match) {
      printf("Matched %d %d\n", begin, end);
    } else {
      printf("Not matched\n");
    }
  }

  return 0;
}
