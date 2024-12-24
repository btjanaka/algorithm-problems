// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 958
// Title: Check Completeness of a Binary Tree
// Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
// Idea: Perform a level-order traversal of the tree. All nodes should be full
// until you reach a non-full node, after which all nodes must be leaves.
// Furthermore, the non-full node can only have a left child.
// Difficulty:
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
  bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    bool shouldBeLeaf = false;
    bool complete = true;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      if (shouldBeLeaf) {
        // We passed the full nodes, so now all must be leaf nodes.
        if (cur->left || cur->right) {
          complete = false;
          break;
        }
      } else {
        bool full = cur->left && cur->right;
        if (full) {
          q.push(cur->left);
          q.push(cur->right);
        } else {
          shouldBeLeaf = true;
          // Checks for the non-full node -- only the left child is allowed to
          // exist.
          if (cur->left) {
            q.push(cur->left);
          } else if (cur->right) {
            // If only the right child exists, the tree is not complete.
            complete = false;
            break;
          }
        }
      }
    }
    return complete;
  }
};
