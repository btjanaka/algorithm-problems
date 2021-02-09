// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) simple-text-editor
// Title: Simple Text Editor
// Link: https://www.hackerrank.com/challenges/simple-text-editor/problem
// Idea: Maintain a stack that contains all the operations one would have to do
// to undo the given operations, e.g. delete when the original operation was
// append. When undo is given, apply the operation at the top of the stack.
// Difficulty: medium
// Tags: stack
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

  string s;

  // Operations required to perform an undo.
  // {op type, {chars to delete (if op is 'd'), str to append (if op is 'a')}}
  stack<pair<char, pair<int, string>>> ops;

  int q, t, k;
  string w;
  cin >> q;
  while (q--) {
    cin >> t;
    switch (t) {
      case 1:
        cin >> w;
        s += w;
        ops.push({'d', {w.size(), ""}});
        break;
      case 2:
        cin >> k;
        ops.push({'a', {-1, s.substr(s.size() - k, k)}});
        s.erase(s.size() - k, k);
        break;
      case 3:
        cin >> k;
        cout << s[k - 1] << '\n';
        break;
      case 4:
        auto op = ops.top();
        ops.pop();
        if (op.first == 'a') {
          s += op.second.second;
        } else {
          s.erase(s.size() - op.second.first, op.second.first);
        }
        break;
    }
  }

  return 0;
}
