// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 104
// Title: Maximum Depth of Binary Tree
// Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Idea: Recur through the binary tree keeping track of depth.
// Difficulty: Easy
// Tags:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int maxDepth2(TreeNode* root, int depth) {
    int leftDepth = 0, rightDepth = 0;
    if (root->left) {
      leftDepth = maxDepth2(root->left, depth + 1);
    }
    if (root->right) {
      rightDepth = maxDepth2(root->right, depth + 1);
    }
    return max(depth, max(leftDepth, rightDepth));
  }

  int maxDepth(TreeNode* root) { return root ? maxDepth2(root, 1) : 0; }
};
