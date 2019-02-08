// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 26
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> copy = std::move(nums);
        nums.clear();
        for(int i = 0; i < copy.size(); ++i) {
            if(i == 0 || copy[i] != copy[i - 1]) {
                nums.push_back(copy[i]);
            }
        }
        return nums.size();
    }
};
