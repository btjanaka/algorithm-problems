// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 215

// Solution 1: Quick-select - O(n)
class Solution {
 public:
  // Implementation of quick-select with O(n) extra memory (for simplicity)
  // L and R are inclusive
  int findKthLargest(vector<int>& nums, vector<int>& buf, int k, int L, int R) {
    if (L == R) return nums[L];
    int pivot = nums[L + rand() % (R - L + 1)];

    int L_i = L, R_i = R;
    for (int i = L; i <= R; ++i) {
      if (nums[i] > pivot) {
        buf[L_i++] = nums[i];
      } else if (nums[i] < pivot) {
        buf[R_i--] = nums[i];
      }
    }

    for (int i = L; i <= R; ++i) nums[i] = buf[i];

    if (k < L_i) return findKthLargest(nums, buf, k, L, L_i - 1);
    if (k > R_i) return findKthLargest(nums, buf, k, R_i + 1, R);
    return pivot;
  }

  int findKthLargest(vector<int>& nums, int k) {
    srand(time(NULL));
    vector<int> buf(nums.size());
    return findKthLargest(nums, buf, k - 1, 0, nums.size() - 1);
  }
};

// Solution 2: Priority Queue - O(n log n)
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (int num : nums) {
      pq.push(num);
    }
    for (int i = 0; i < k - 1; ++i) pq.pop();
    return pq.top();
  }
};
