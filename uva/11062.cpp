// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 11062
// Title: Andy's Second Dictionary
// Link:
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=2003
// Idea: Use an ordered set to store the words. Most of the difficulty is in
// parsing the words properly.
// Difficulty: Easy
// Tags:
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  set<string> words;

  string s;
  char ch1 = 0, ch2 = getchar();
  while (ch1 != EOF) {
    ch1 = ch2;
    ch2 = getchar();

    if (isalpha(ch1)) {
      s.push_back(tolower(ch1));
    } else if (ch1 == '-' && ch2 == '\n') {
      // Advance so that we skip the newline and pick up the next part of the
      // word.
      ch1 = ch2;
      ch2 = getchar();
    } else if (ch1 == '-' && ch2 != '\n') {
      s.push_back(ch1);
    } else {
      // Word ended.
      if (s.size()) {
        words.insert(s);
        s.clear();
      }
    }
  }

  for (const auto& w : words) {
    cout << w << '\n';
  }

  return 0;
}
