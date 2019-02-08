// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 127
#include <bits/stdc++.h>
#define GET(x) scanf("%d", &x)
#define GED(x) scanf("%lf", &x)
typedef long long ll;
using namespace std;

list<stack<pair<char, char>>>::iterator prev3(
    list<stack<pair<char, char>>>::iterator itr) {
  --itr;
  --itr;
  --itr;
  return itr;
}

list<stack<pair<char, char>>>::iterator prev1(
    list<stack<pair<char, char>>>::iterator itr) {
  --itr;
  return itr;
}

bool is_match(pair<char, char> a, pair<char, char> b) {
  return a.first == b.first || a.second == b.second;
}

bool make_move(list<stack<pair<char, char>>>& cards) {
  auto itr = cards.begin();
  for (int i = 0; i < cards.size(); ++i) {
    if (i > 2 && is_match(itr->top(), prev3(itr)->top())) {
      prev3(itr)->push(itr->top());
      itr->pop();
      if (itr->size() == 0) cards.erase(itr);
      return true;
    } else if (i > 0 && is_match(itr->top(), prev1(itr)->top())) {
      prev1(itr)->push(itr->top());
      itr->pop();
      if (itr->size() == 0) cards.erase(itr);
      return true;
    }
    ++itr;
  }
  return false;
}

int main() {
  char rank, suit;
  while (scanf(" %c%c", &rank, &suit)) {
    if (rank == '#') break;
    list<stack<pair<char, char>>> cards;
    cards.push_back(stack<pair<char, char>>());
    cards.back().push({rank, suit});
    for (int i = 0; i < 51; ++i) {
      scanf(" %c%c", &rank, &suit);
      cards.push_back(stack<pair<char, char>>());
      cards.back().push({rank, suit});
      while (make_move(cards))
        ;
    }

    if (cards.size() == 1) {
      printf("1 pile remaining: %d\n", (int)cards.front().size());
    } else {
      printf("%d piles remaining:", (int)cards.size());
      for (auto& p : cards) printf(" %d", (int)p.size());
      printf("\n");
    }
  }
  return 0;
}
