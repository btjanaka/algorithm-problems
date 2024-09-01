// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 10815
// Title: Andy's First Dictionary
// Link:
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1756&mosmsg=Submission+received+with+ID+29740672
// Idea: Use an ordered set to maintain unique words. There are some issues with
// parsing, e.g., a word is a sequence of letters and so the words may not be
// whitespace-separated.
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

  string line;
  while (getline(cin, line)) {
    string s;
    line.push_back('&');  // This non-alphabetic character will cause the else
                          // statement below to always activate so that we can
                          // catch words that take up the whole line.
    for (const auto& c : line) {
      if (isalpha(c)) {
        // Add the character to the word.
        s.push_back(tolower(c));
      } else {
        // We have reached a non-alphabet character, so add this word and make a
        // new word.
        if (s.size()) {
          words.insert(s);
          s = "";
        }
      }
    }
  }

  for (const auto& w : words) {
    cout << w << '\n';
  }

  return 0;
}
