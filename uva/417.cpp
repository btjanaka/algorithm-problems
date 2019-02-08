// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 417
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

vector<string> words;

void precalc(string& s) {
  if (s.size() > 5) return;
  char begin = s.size() == 0 ? 'a' : s.back() + 1;
  for (char ch = begin; ch <= 'z'; ++ch) {
    s.push_back(ch);
    words.push_back(s);
    precalc(s);
    s.pop_back();
  }
}

int main() {
  string s;
  precalc(s);
  sort(words.begin(), words.end(), [](const string& a, const string& b) {
    if (a.size() != b.size())
      return a.size() < b.size();
    else
      return a < b;
  });
  unordered_map<string, int> vals;
  for (int i = 0; i < words.size(); ++i) {
    vals[words[i]] = i + 1;
  }
  string buf;
  while (cin >> buf) {
    if (vals.find(buf) != vals.end()) {
      cout << vals[buf] << endl;
    } else {
      cout << 0 << endl;
    }
  }
  return 0;
}
