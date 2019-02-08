// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 347
#include <bits/stdc++.h>
using namespace std;

int num_len(int num) {
  int res = 0;
  for (; num > 0; num /= 10) ++res;
  return res;
}

int is_runaround(int num) {
  int len = num_len(num);
  int copy = num;

  // Determine unique digits and cache digits
  int digit_set = 0;  // bit i from right (with 1-based indexing) tells if digit
                      // i is already encountered
  int digit_arr[10];  // leftmost digit stored at index 0
  int i = 0;
  for (; copy > 0; copy /= 10) {
    int d = copy % 10;
    if (digit_set & (1 << d)) return 0;
    digit_set |= 1 << d;
    digit_arr[len - i - 1] = d;
    ++i;
  }

  // Run around...
  int curr = digit_arr[0];
  int place = 0;
  int visited = 0;  // Tells what places in the number have been visited
  for (int i = 0; i < len; ++i) {
    if (visited & (1 << place)) return 0;
    visited |= 1 << place;
    place = (place + curr) % len;
    curr = digit_arr[place];
  }

  // Check if ended up at initial position
  return curr == digit_arr[0];
}

int main() {
  int num;
  for (int i = 1; scanf("%d", &num) && num != 0; ++i) {
    for (; !is_runaround(num); ++num) {
    }
    printf("Case %d: %d\n", i, num);
  }
  return 0;
}
