// Author: Meta Novitia
// Edited by: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) gcds
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int gcd(int x, int y) {
  if (y) {
    return gcd(y, x % y);
  }
  return x;
}

int main() {
  int n;

  while (cin >> n) {
    bool unique[101] = {};      // unique GCD's (basically just a set)
    bool considered[101] = {};  // GCD's currently being considered
    int x, y, count = 0;
    while (n--) {
      // Mark current number as considered
      cin >> x;
      considered[x] = true;

      // Iterate through all numbers being considered - iterate in ascending
      // order to avoid repeats
      for (int i = 1; i < 101; ++i) {
        // If a number is considered, mark its gcd. The number will be marked
        // as gcd'ing with itself when you reach i = x. You will also mark gcd
        // with all the previous numbers, as those gcd's are stored in the
        // |considered| array. |considered| essentially tells what other gcd's
        // we have seen in the past; we do not care where that gcd occurred,
        // only that we have seen it.
        if (considered[i]) {
          considered[i] = false;
          y = gcd(x, i);
          if (!unique[y]) {
            unique[y] = true;
            count++;
          }
          considered[y] = true;
        }
      }
    }

    cout << count << endl;
  }

  return 0;
}
