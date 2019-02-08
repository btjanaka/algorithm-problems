// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11498
#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  cin >> k;
  while (k != 0) {
    int x, y;
    cin >> x >> y;
    while (k--) {
      int tx, ty;
      cin >> tx >> ty;
      if (tx == x || ty == y) {
        cout << "divisa" << endl;
      } else if (tx < x && ty > y) {
        cout << "NO" << endl;
      } else if (tx < x && ty < y) {
        cout << "SO" << endl;
      } else if (tx > x && ty < y) {
        cout << "SE" << endl;
      } else if (tx > x && ty > y) {
        cout << "NE" << endl;
      }
    }
    cin >> k;
  }
  return 0;
}
