// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 462
#include <bits/stdc++.h>
using namespace std;

int SUITS[] = {'S', 'H', 'D', 'C'};
int suit_trans(char suit) {
  for (int i = 0; i < 4; ++i) {
    if (SUITS[i] == suit) return i;
  }
  return -1;
}

int CARDS[] = {'A', '1', '2', '3', '4', '5', '6',
               '7', '8', '9', 'T', 'J', 'Q', 'K'};
int card_trans(char card) {
  for (int i = 0; i < 14; ++i) {
    if (CARDS[i] == card) return i;
  }
  return -1;
}

int main() {
  char buf[100];
  while (fgets(buf, 100, stdin) != NULL) {
    *strrchr(buf, '\n') = 0;
    int cards[4][14];
  }
  return 0;
}
