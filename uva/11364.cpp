// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11364
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l = 100;
    int r = -1;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      if (x < l) l = x;
      if (x > r) r = x;
    }
    cout << 2 * (r - l) << endl;
  }
  return 0;
}

/*
Explanation for this solution:
No matter where you park, you will still have to walk
all the way to the rightmost place, then walk all the way
back to the leftmost place. Finally, you have to walk all
the way back to your car. That means you alwyas have to
walk at least 2 * (r - l).
*/