// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) dunglish
// Title: Dunglish
// Link: https://open.kattis.com/problems/dunglish
// Idea: Implementation - input the dictionary and try to find all translations.
// Difficulty: medium
// Tags: implementation
#include <iostream>
#include <string>
#include <unordered_map>
#define GET(x) scanf("%d", &x)
typedef long long ll;
using namespace std;

struct Word {
  ll correct;
  ll incorrect;
  string trans;
};

int main() {
  int n;
  GET(n);
  string sentence[20];
  for (int i = 0; i < n; ++i) cin >> sentence[i];

  // Input the dictionary
  int m;
  GET(m);
  unordered_map<string, Word> dict;
  string buf;
  string trans;
  string corr;
  for (int i = 0; i < m; ++i) {
    cin >> buf;
    if (dict.find(buf) == dict.end()) {
      dict.insert(make_pair(buf, Word()));
      dict[buf].correct = 0;
      dict[buf].incorrect = 0;
      dict[buf].trans = "";
    }

    cin >> trans;
    dict[buf].trans = trans;
    cin >> corr;
    if (corr == "correct") {
      dict[buf].correct++;
    } else {
      dict[buf].incorrect++;
    }
  }

  // Count up total translations
  long long tot = 1;
  long long good = 1;
  for (int i = 0; i < n; ++i) {
    good *= dict[sentence[i]].correct;
    tot *= (dict[sentence[i]].correct + dict[sentence[i]].incorrect);
  }

  // Output
  if (tot == 1) {
    for (int i = 0; i < n; ++i) {
      if (i != 0) putchar(' ');
      printf("%s", dict[sentence[i]].trans.c_str());
    }
    printf("\n");
    if (good == 1) {
      printf("correct\n");
    } else {
      printf("incorrect\n");
    }
  } else {
    printf("%lld correct\n", good);
    printf("%lld incorrect\n", tot - good);
  }

  return 0;
}
