// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) no-prefix-set
// Title: No Prefix Set
// Link: https://www.hackerrank.com/challenges/no-prefix-set/problem
// Idea: Create a trie as usual, but when inserting string s into the trie,
// check for two conditions. First, check if we are appending to a leaf node.
// If we are, there was another string that is a prefix of s. Next, check if
// s already existed in the trie; if so, it was the prefix of another string.
// Difficulty: medium
// Tags: trie, string
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

struct Node {
  bool has_children;
  vector<unique_ptr<Node>> children;
  Node() : has_children(false), children('j' - 'a' + 1) {}
};

struct Trie {
  unique_ptr<Node> root;  // Be good memory citizens :D
  Trie() : root(new Node()) {}

  // Adds the string to the trie. Returns true if s is a prefix or if there is a
  // prefix of s.
  bool add(const string& s) {
    Node* cur = root.get();

    int i = 0;
    while (true) {
      char ch = s[i];

      // Walk down the trie until we need to actually add characters.
      if (cur->children[ch - 'a'] == nullptr) {
        // If we reached a leaf (i.e. the node has no children and it is not
        // the root node), there was a prefix to this string.
        if (cur != root.get() && !(cur->has_children)) return true;
        break;
      }

      // Walk to next node and character.
      cur = cur->children[ch - 'a'].get();
      ++i;

      // This string already existed in the trie.
      if (i >= s.size()) return true;
    }

    // Now add remaining characters.
    for (; i < s.size(); ++i) {
      char ch = s[i];
      Node* next = new Node();
      cur->has_children = true;
      cur->children[ch - 'a'] = unique_ptr<Node>(next);
      cur = next;
    }

    return false;
  }
};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  string s;
  Trie trie;
  bool ok = true;
  while (n--) {
    cin >> s;
    if (trie.add(s)) {
      cout << "BAD SET\n" << s << "\n";
      ok = false;
      break;
    }
  }
  if (ok) cout << "GOOD SET\n";

  return 0;
}
