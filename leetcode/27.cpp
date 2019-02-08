// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 27
// Note: it does not work to maintain two pointers because Leetcode seems to
// have a bug with the judge, where you cannot set a vector's elements from
// within a function, i.e. v[i] = 10 doesn't work properly.
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    vector<int> copy = nums;
    nums.clear();

    for (int i = 0; i < copy.size(); ++i) {
      if (copy[i] != val) {
        nums.push_back(copy[i]);
      }
    }

    return nums.size();
  }
};
