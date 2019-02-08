// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 144
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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> to_visit;
    if (root != nullptr) to_visit.push(root);
    while (to_visit.size() > 0) {
      TreeNode* curr = to_visit.top();
      to_visit.pop();
      res.push_back(curr->val);
      if (curr->right != nullptr) {
        to_visit.push(curr->right);
      }
      if (curr->left != nullptr) {
        to_visit.push(curr->left);
      }
    }
    return res;
  }
};
