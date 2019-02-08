// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 188
#include <bits/stdc++.h>
using namespace std;

int words[15];

int convert_to_num(char* token) {
  int res = 0;
  for (int i = 0; token[i] != 0; ++i) {
    res <<= 5;
    res += token[i] - 'a' + 1;
  }
  return res;
}

int main() {
  char buf[100];
  char copy[100];
  while (fgets(buf, 100, stdin)) {
    // Input
    int n = 0;
    strcpy(copy, buf);
    for (char* token = strtok(buf, " \n"); token != NULL;
         token = strtok(NULL, " \n")) {
      words[n++] = convert_to_num(token);
    }

    // Processing
    int c = 1;
    while (1) {
      bool ok = true;
      int next_jump_c = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
          bool equal = (c / words[i]) % n == (c / words[j]) % n;
          ok = !equal && ok;
          if (equal)
            next_jump_c = max(next_jump_c, min((c / words[i] + 1) * words[i],
                                               (c / words[j] + 1) * words[j]));
        }
      }
      if (ok) break;
      c = next_jump_c;
    }

    // Output
    printf("%s", copy);
    printf("%d\n", c);
    putchar('\n');
  }
  return 0;
}
