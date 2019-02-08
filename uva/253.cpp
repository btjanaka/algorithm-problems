// Author: btjanaka (Bryon Tjanaka)
// Problem: (UVa) 253
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORe(i, a, b) for (int i = a; i <= b; ++i)
#define PAI(arr, len) /*Print array of integers*/ \
  for (int _i = 0; _i < len; ++_i) {              \
    if (_i != len - 1) {                          \
      printf("%d ", arr[_i]);                     \
    } else {                                      \
      printf("%d\n", arr[_i]);                    \
    }                                             \
  }
#define GET(x) \
  int x;       \
  scanf("%d", &x);
typedef long long ll;
using namespace std;

// x-axis has 1, 3, 6, 4 (AKA 0, 2, 5, 3)
void rotate_x(char tmp[], int x) {
  for (int i = 0; i < x; ++i) {
    char t = tmp[0];
    tmp[0] = tmp[2];
    tmp[2] = tmp[5];
    tmp[5] = tmp[3];
    tmp[3] = t;
  }
}

// y-axis has 1, 2, 6, 5 (AKA 0, 1, 5, 4)
void rotate_y(char tmp[], int y) {
  for (int i = 0; i < y; ++i) {
    char t = tmp[0];
    tmp[0] = tmp[1];
    tmp[1] = tmp[5];
    tmp[5] = tmp[4];
    tmp[4] = t;
  }
}

// z-axis has 3, 2, 4, 5 (AKA 2, 1, 3, 4)
void rotate_z(char tmp[], int z) {
  for (int i = 0; i < z; ++i) {
    char t = tmp[2];
    tmp[2] = tmp[1];
    tmp[1] = tmp[3];
    tmp[3] = tmp[4];
    tmp[4] = t;
  }
}

int main() {
  char cube1[8];
  char cube2[8];
  char tmp[8];
  while (scanf("%6s%6s", cube1, cube2) > 0) {
    bool ok = false;
    for (int x = 0; x < 4; ++x) {
      for (int y = 0; y < 4; ++y) {
        for (int z = 0; z < 4; ++z) {
          strcpy(tmp, cube2);
          rotate_x(tmp, x);
          rotate_y(tmp, y);
          rotate_z(tmp, z);
          if (strcmp(cube1, tmp) == 0) {
            ok = true;
            goto done;
          }
        }
      }
    }
  done:
    if (ok) {
      printf("TRUE\n");
    } else {
      printf("FALSE\n");
    }
  }
  return 0;
}
