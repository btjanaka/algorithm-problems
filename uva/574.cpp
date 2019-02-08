// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 574
// NOTE: iterative does not work for this problem (at least, the way that
// involves going through all possible subsets of the array) does not work
// because different subsets can hold the same numbers (since they can repeat),
// and we only want distinct solutions.

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

bool found;
int nums[15];
int res[15];

// curr: current sum
// t: target
// res_pos: current position in result array
// nums_pos: current position in nums array
// n: number of numbers in nums array
void backtrack(int curr_sum, int t, int res_pos, int nums_pos, int n) {
  // Debugging
  // printf("%d : ", curr_sum);
  // PAI(res, res_pos + 1);

  // base case: nums_pos is equal to n, meaning that there are no more numbers
  // left in the array to use, or curr_sum is equal to t, the target
  if (nums_pos == n || curr_sum >= t) {
    if (curr_sum == t) {
      for (int i = 0; i <= res_pos; ++i) {
        if (i == 0) {
          printf("%d", res[i]);
        } else {
          printf("+%d", res[i]);
        }
      }
      PLN;
      found = true;
    }
    return;
  }

  // Count the number of numbers with the same value as the current number.
  // At the same time, push |same| copies of the number into res.
  // After this, recur with all multiples of the number.
  int same;
  for (same = 0; nums_pos + same < n && nums[nums_pos + same] == nums[nums_pos];
       ++same) {
    res[res_pos + same + 1] = nums[nums_pos];
  }

  // Go in reverse order to enforce sorted output
  for (int i = same; i >= 0; --i) {
    backtrack(curr_sum + nums[nums_pos] * i, t, res_pos + i, nums_pos + same,
              n);
  }
}

int main() {
  int t, n;
  while (GET(t) && GET(n) && n) {
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; ++i) {
      GET(nums[i]);
    }
    found = false;
    printf("Sums of %d:\n", t);
    backtrack(0, t, -1, 0, n);
    if (!found) printf("NONE\n");
  }
  return 0;
}
