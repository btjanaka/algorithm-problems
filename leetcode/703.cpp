// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 703
// Title: Kth Largest Element in a Stream
// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Idea: Maintain a sorted list or priority queue and repeatedly add elements to
// the data structure.
// Difficulty: Easy
// Tags:

//
// Sorted list idea (linear time).
//
class KthLargest {
 private:
  int k;
  vector<int>& nums;

 public:
  KthLargest(int k, vector<int>& nums) : k(k), nums(nums) {
    // Initialize by sorting and removing unneeded elements.

    if (nums.size() > 0) {
      sort(nums.begin(), nums.end(), greater<int>());
    }

    while (nums.size() > k) {
      nums.pop_back();
    }
  }

  int add(int val) {
    int insertion_idx = nums.size();
    int tmp;

    if (nums.size() < k) {
      nums.push_back(INT_MIN);
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (val > nums[i]) {
        tmp = nums[i];
        nums[i] = val;
        val = tmp;
        insertion_idx = i;
        break;
      }
    }

    for (int i = insertion_idx + 1; i < nums.size(); ++i) {
      tmp = nums[i];
      nums[i] = val;
      val = tmp;
    }

    return nums[k - 1];
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

//
// Priority queue idea.
//

class KthLargest {
 private:
  int k;
  priority_queue<int, vector<int>, greater<int>> pq;

 public:
  KthLargest(int k, vector<int>& nums) : k(k) {
    for (const auto& x : nums) {
      add(x);
    }
  }

  int add(int val) {
    // Always add to the pq. It will always store the lowest item at the top,
    // and if we have more than k items, we can pop.
    pq.push(val);

    if (pq.size() > k) pq.pop();

    return pq.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
