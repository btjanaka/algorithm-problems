// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 31
// See: https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if (n == 0 || n == 1) return;

    // Find beginning of non-increasing suffix
    int suffix = n - 1;
    while (suffix > 0 && nums[suffix] <= nums[suffix - 1]) {
      --suffix;
    }

    // Only go looking for a successor if the suffix is not occupying the whole
    // array.
    if (suffix != 0) {
      int pivot = nums[suffix - 1];
      int next;
      for (next = n - 1; nums[next] <= pivot; --next)
        ;

      // Swap the successor and pivot
      int tmp = nums[next];
      nums[next] = nums[suffix - 1];
      nums[suffix - 1] = tmp;
    }

    // Reverse suffix
    int suffix_len = n - suffix;
    for (int i = 0; i < suffix_len / 2; ++i) {
      int tmp = nums[i + suffix];
      nums[i + suffix] = nums[n - i - 1];
      nums[n - i - 1] = tmp;
    }
  }
};
