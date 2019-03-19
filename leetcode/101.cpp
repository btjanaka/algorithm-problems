// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 101
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
  bool mirror(TreeNode* left, TreeNode* right) {
    if (left == nullptr ^ right == nullptr) return false;
    if (left == nullptr & right == nullptr) return true;
    return left->val == right->val && mirror(left->left, right->right) &&
           mirror(left->right, right->left);
  }

  bool isSymmetric(TreeNode* root) {
    if (root == nullptr) return true;
    return mirror(root->left, root->right);
  }
};
