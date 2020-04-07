// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 102
// Title: Binary Tree Level Order Traversal
// Link: https://leetcode.com/problems/binary-tree-level-order-traversal
// Idea: Breadth first traversal, but store everything you visit.
// Difficulty: medium
// Tags: binary-tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<TreeNode*>> res(1);
    if (root) res.back().push_back(root);
    while (res.back().size() > 0) {
      vector<TreeNode*> next;
      for (TreeNode* u : res.back()) {
        if (u->left) next.push_back(u->left);
        if (u->right) next.push_back(u->right);
      }
      res.push_back(next);
    }
    res.pop_back();
    vector<vector<int>> nums(res.size());
    for (int i = 0; i < res.size(); ++i) {
      for (int j = 0; j < res[i].size(); ++j) {
        nums[i].push_back(res[i][j]->val);
      }
    }
    return nums;
  }
};
