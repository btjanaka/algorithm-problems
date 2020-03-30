// Author: btjanaka (Bryon Tjanaka)
// Problem: (Kattis) fizzbuzz
// Title: FizzBuzz
// Link: https://open.kattis.com/problems/fizzbuzz
// Idea:
// Difficulty: easy
// Tags: implementation
#include <iostream>
using namespace std;

int main() {
  int x, y, n;
  cin >> x >> y >> n;
  for (int i = 1; i <= n; i++) {
    if (i % x == 0 && i % y == 0) {
      cout << "FizzBuzz";
    } else if (i % x == 0) {
      cout << "Fizz";
    } else if (i % y == 0) {
      cout << "Buzz";
    } else {
      cout << i;
    }
    cout << endl;
  }
  return 0;
}
