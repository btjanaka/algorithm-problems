// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12356
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  int s, b;
  while (GET(s) && GET(b) && !(!s && !b)) {
    int left[s + 2], right[s + 2];
    bool deleted[s + 2];
    // set default values
    memset(deleted, false, sizeof(deleted));
    for (int i = 1 < 1; i <= s; ++i) {
      left[i] = i - 1;
      right[i] = i + 1;
    }

    for (int i = 0; i < b; ++i) {
      int l, r;
      GET(l);
      GET(r);
      for (int j = l; j <= r; ++j) deleted[j] = true;
      right[l] = r + 1;
      left[r] = l - 1;

      // Traverse left and right.
      // As we travel, cache all the visited nodes and then set their new
      // neighbors to the final destination
      vector<int> visited(1, l);
      int left_bound = left[l];
      while (deleted[left_bound]) {
        visited.push_back(left_bound);
        left_bound = left[left_bound];
      }
      for_each(visited.begin(), visited.end(),
               [&](int i) { left[i] = left_bound; });

      visited.clear();
      visited.push_back(r);
      int right_bound = right[r];
      while (deleted[right_bound]) {
        visited.push_back(right_bound);
        right_bound = right[right_bound];
      }
      for_each(visited.begin(), visited.end(),
               [&](int i) { right[i] = right_bound; });

      // output
      if (left_bound == 0) {
        printf("* ");
      } else {
        printf("%d ", left_bound);
      }
      if (right_bound == s + 1) {
        printf("*\n");
      } else {
        printf("%d\n", right_bound);
      }
    }
    printf("-\n");
  }
  return 0;
}
