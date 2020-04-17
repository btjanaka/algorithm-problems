// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 112
// Title: Path Sum
// Link: https://leetcode.com/problems/path-sum/
// Idea: Recursively check each node. Keep in mind that the node has to be a
// leaf, node which only happens if it has no children.
// Difficulty: easy
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
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr) return false;
    if (root->left == NULL && root->right == NULL)
      return sum == root->val;  // Leaf node check.
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
  }
};
