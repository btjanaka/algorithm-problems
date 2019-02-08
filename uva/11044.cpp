// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11044
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int a, b;
    cin >> a >> b;
    int x = (a - 2) % 3 == 0 ? 0 : 1;
    int y = (b - 2) % 3 == 0 ? 0 : 1;
    cout << ((a - 2) / 3 + x) * ((b - 2) / 3 + y) << endl;
  }
  return 0;
}