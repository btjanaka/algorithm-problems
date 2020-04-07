// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 226
// Title: Invert Binary Tree
// Link: https://leetcode.com/problems/invert-binary-tree
// Idea: Recursively invert the children.
// Difficulty: easy
// Tags: binary-tree, recursion
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
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return root;
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};
