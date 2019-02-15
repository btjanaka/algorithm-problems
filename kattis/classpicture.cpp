// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) classpicture
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;
typedef pair<int, int> ii;

bool works(vector<string>& ppl,
           unordered_map<string, unordered_set<string>>& dislike) {
  for (int i = 0; i < ppl.size(); ++i) {
    if (i < ppl.size() - 1 &&
        dislike[ppl[i]].find(ppl[i + 1]) != dislike[ppl[i]].end()) {
      return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  while (cin >> n) {
    vector<string> ppl;
    unordered_map<string, unordered_set<string>> dislike;
    string s;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      ppl.push_back(s);
      dislike[s] = {};
    }
    sort(ppl.begin(), ppl.end());

    int m;
    cin >> m;
    string a, b;
    while (m--) {
      cin >> a >> b;
      dislike[a].insert(b);
      dislike[b].insert(a);
    }

    // iterate through all permutations of people
    bool ok = false;
    if (works(ppl, dislike)) {
    }
    while (!ok && next_permutation(ppl.begin(), ppl.end())) {
      ok = works(ppl, dislike);
    }

    if (ok) {
      for (int i = 0; i < n; ++i) {
        printf("%s%c", ppl[i].c_str(), i == n - 1 ? '\n' : ' ');
      }
    } else {
      printf("You all need therapy.\n");
    }
  }
  return 0;
}
