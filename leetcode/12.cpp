// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 12
// Title: Integer to Roman
// Link: https://leetcode.com/problems/integer-to-roman
// Idea: Pretty straightforward -- just map the digits to their roman numeral
// representation.
// Difficulty: medium
// Tags: implementation
constexpr static char* ones[10] = {"",  "I",  "II",  "III",  "IV",
                                   "V", "VI", "VII", "VIII", "IX"};
constexpr static char* tens[10] = {"",  "X",  "XX",  "XXX",  "XL",
                                   "L", "LX", "LXX", "LXXX", "XC"};
constexpr static char* hundreds[10] = {"",  "C",  "CC",  "CCC",  "CD",
                                       "D", "DC", "DCC", "DCCC", "CM"};
constexpr static char* thousands[10] = {"", "M", "MM", "MMM"};

class Solution {
 public:
  string intToRoman(int num) {
    char res[20];
    res[0] = 0;

    strcat(res, thousands[num / 1000]);
    strcat(res, hundreds[(num % 1000) / 100]);
    strcat(res, tens[(num % 100) / 10]);
    strcat(res, ones[num % 10]);

    return res;
  }
};
