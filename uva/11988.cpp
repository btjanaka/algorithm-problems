// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11988
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

int main() {
  string buf;
  while (cin >> buf) {
    list<char> text;
    list<char>::iterator cursor = text.begin();
    for (char ch : buf) {
      switch (ch) {
        case '[':
          cursor = text.begin();
          break;
        case ']':
          cursor = text.end();
          break;
        default:
          text.insert(cursor, ch);
          break;
      }
    }
    for_each(text.begin(), text.end(), [](char ch) { putchar(ch); });
    putchar('\n');
  }
  return 0;
}
