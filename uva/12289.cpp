// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 12289
#include <bits/stdc++.h>

using namespace std;

int count_similarities(char *buf, const char *target, int n) {
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    if (buf[i] == target[i]) ++sum;
  }
  return sum;
}

int main() {
  int t;
  scanf("%d\n", &t);
  char buf[10];

  while (t--) {
    scanf("%s", buf);
    if (strlen(buf) == 5)
      printf("3\n");
    else {
      if (count_similarities(buf, "one", 3) >= 2)
        printf("1\n");
      else
        printf("2\n");
    }
  }

  return 0;
}
