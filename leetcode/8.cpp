// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 8
class Solution {
 public:
  int myAtoi(string str) {
    int num_start;
    int num_end;
    long long res = 0;
    int sign;

    // Parse out whitespace; determine beginning of number
    for (num_start = 0; num_start < str.size() && str[num_start] == ' ';
         ++num_start)
      ;
    if (num_start == str.size())
      return 0;  // String is empty or just whitespace

    // Determine sign, and move num_start past sign if necessary
    if (str[num_start] == '-') {
      ++num_start;
      sign = -1;
    } else if (str[num_start] == '+') {
      ++num_start;
      sign = 1;
    } else {
      sign = 1;
    }

    // Return 0 if num_start is not currently on a digit
    if (num_start == str.size() || !isdigit(str[num_start])) return 0;

    // Determine end of number
    for (num_end = num_start; num_end < str.size() && isdigit(str[num_end]);
         ++num_end)
      ;

    // Convert to number
    for (int i = num_start; i < num_end; ++i) {
      res *= 10;
      res += str[i] - '0';

      // Make sure that long won't be maxed out
      if (sign == 1 && res > INT_MAX) return INT_MAX;
      if (sign == -1 && res > -long(INT_MIN)) return INT_MIN;
    }

    // Process final result
    res *= sign;
    if (res < INT_MIN) return INT_MIN;
    if (res > INT_MAX) return INT_MAX;
    return res;
  }
};
