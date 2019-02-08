// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 624
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

int n;
int n_tracks;
int tracks[25];

// Ok, so technically this was supposed to be a recursive backtracking problem.
// But it looked like it could be solved iteratively, so... why not?

int main() {
  while (GET(n) > 0) {
    // Input
    GET(n_tracks);
    FOR(i, 0, n_tracks) GET(tracks[i]);

    // Go through all possible subsets and find the one that is most fitting
    int max_time = 0;   // Amount of time for most fitting solution
    int max_count = 0;  // Number of tracks in the most fitting solution
    int res[25];        // Tracks in most fitting solution
    int tmp[25];        // Holds tracks being considered
    FOR(i, 0, 1 << n_tracks) {
      // Add up all the times and record them in tmp
      int tmp_time = 0;
      int tmp_count = 0;
      FOR(j, 0, n_tracks) {
        if (i & (1 << j)) {
          tmp[tmp_count++] = tracks[j];
          tmp_time += tracks[j];
        }
      }
      // Either the time must be greater, or the time is equal and there are
      // more tracks. In any case, the time cannot exceed n.
      if (tmp_time <= n && (tmp_time > max_time ||
                            (tmp_time == max_time && tmp_count > max_count))) {
        max_time = tmp_time;
        max_count = tmp_count;
        memcpy(res, tmp, sizeof(int) * tmp_count);
      }
    }
    FOR(i, 0, max_count) printf("%d ", res[i]);
    printf("sum:%d\n", max_time);
  }
  return 0;
}
