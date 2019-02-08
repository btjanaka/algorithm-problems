// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 156
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // bool tells if this anagram has been seen multiple times
  unordered_map<string, pair<string, bool>> words;
  string s;
  while (cin >> s && s != "#") {
    string cpy = s;
    for_each(cpy.begin(), cpy.end(), [](char& ch) { ch = tolower(ch); });
    sort(cpy.begin(), cpy.end());
    if (words.find(cpy) == words.end()) {
      words[cpy] = {s, false};
    } else {
      words[cpy].second = true;
    }
  }

  // output
  vector<string> res;
  for (const auto& x : words) {
    if (!x.second.second) {
      res.push_back(x.second.first);
    }
  }
  sort(res.begin(), res.end());

  for_each(res.begin(), res.end(), [](const string& x) { cout << x << endl; });
  return 0;
}
