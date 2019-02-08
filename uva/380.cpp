// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 380
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
  int n;
  GET(n);

  printf("CALL FORWARDING OUTPUT\n");

  // Store call forwarding as a map of source to a vector of arrays.
  // Each array is of size 3 and tells a time, duration, and target.
  map<int, vector<int*>> forwards;

  FORe(i, 1, n) {
    // Leaving out free-ing of allocated memory - memory leaks - oops
    forwards.clear();

    // Record forwarding times
    int source;
    while (scanf("%d", &source) && source != 0) {
      // time - duration - target
      int* entry = (int*)calloc(sizeof(int), 3);
      scanf("%d %d %d", entry, entry + 1, entry + 2);

      if (forwards.find(source) == forwards.end()) {
        forwards.insert(std::pair<int, vector<int*>>(source, {}));
      }

      forwards[source].push_back(entry);
    }

    printf("SYSTEM %d\n", i);

    // Process all times
    int time;
    int extension;
    while (scanf("%d", &time) && time != 9000) {
      scanf("%d", &extension);

      // Iterate until there are no more redirects
      int ext_itr = extension;
      while (true) {
        // Exit if cannot find another forwarding
        if (forwards.find(ext_itr) == forwards.end()) break;

        // Try to find a forwarding
        bool found = false;
        for (auto fwd : forwards[ext_itr]) {
          if (fwd[0] <= time && time <= (fwd[0] + fwd[1])) {
            found = true;
            ext_itr = fwd[2];
            // 9999 if reached original
            if (ext_itr == extension) {
              found = false;
              ext_itr = 9999;
            }
            break;
          }
        }

        // Break if could not find
        if (!found) break;
      }
      printf("AT %04d CALL TO %04d RINGS %04d\n", time, extension, ext_itr);
    }
  }

  printf("END OF OUTPUT\n");

  return 0;
}
