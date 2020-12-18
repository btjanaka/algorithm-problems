// Author: btjanaka (Bryon Tjanaka)
// Problem: (HackerRank) contacts
// Title: Contacts
// Link: https://www.hackerrank.com/challenges/contacts/problem
// Idea: Construct a trie and use that to perform all operations.
// Difficulty: medium
// Tags: trie, string
#include <bits/stdc++.h>

using namespace std;

struct Node {
  int count;
  vector<Node*> children;
  Node() : count(0), children(26, nullptr) {}
};

struct Trie {
  Trie() : root(new Node()) {}
  Node* root;

  void add(const string& name) {
    ++(root->count);
    Node* cur = root;
    for (int i = 0; i < name.size(); ++i) {
      int idx = name[i] - 'a';
      if (cur->children[idx] == nullptr) cur->children[idx] = new Node();
      cur = cur->children[idx];
      ++(cur->count);
    }
  }

  int find(const string& name) {
    Node* cur = root;
    for (int i = 0; i < name.size(); ++i) {
      int idx = name[i] - 'a';
      if (cur->children[idx] == nullptr) return 0;
      cur = cur->children[idx];
    }
    return cur->count;
  }
};

int main() {
  int n;
  cin >> n;
  Trie trie;
  while (n--) {
    string cmd, name;
    cin >> cmd >> name;
    if (cmd == "add")
      trie.add(name);
    else {
      cout << trie.find(name) << "\n";
    }
  }
  return 0;
}
