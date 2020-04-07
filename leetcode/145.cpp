// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 145
// Title: Binary Tree Postorder Traversal
// Link: https://leetcode.com/problems/binary-tree-postorder-traversal
// Idea: See comments.
// Difficulty: hard
// Tags: binary-tree, implementation

// Solution 1
// Modifies the tree but easy to understand.
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
  vector<int> postorderTraversal(TreeNode* root) {
    // Strategy is to delete edges as we go. This way, we can put all the
    // nodes on the stack, but as we go back, we won't need to add on new
    // children because the edges to them are deleted.
    vector<int> res;
    stack<TreeNode*> to_visit;
    if (root != NULL) to_visit.push(root);
    while (to_visit.size() > 0) {
      TreeNode* curr = to_visit.top();
      if (curr->left == NULL && curr->right == NULL) {
        // Only add this node if both of its children are null. This way,
        // we only add a node if its children have been covered first.
        // (children of a node are set to null when the children are
        // pushed onto the stack).
        to_visit.pop();
        res.push_back(curr->val);
        continue;
      }
      if (curr->right != NULL) {
        to_visit.push(curr->right);
        curr->right = NULL;
      }
      if (curr->left != NULL) {
        to_visit.push(curr->left);
        curr->left = NULL;
      }
    }
    return res;
  }
};

// Solution 2
// Doesn't modify the tree
// Reference: https://articles.leetcode.com/binary-tree-post-order-traversal/
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
  vector<int> postorderTraversal(TreeNode* root) {
    // Strategy is to keep track of a prev and a curr. This solution requires
    // thinking a lot about how a post-order traversal works.
    //
    // If prev is parent of curr, we are going down the tree. In this case, we
    // would want to keep going down the tree, so we try to go to the left. If
    // left is not available, check if right is available, and go to it if
    // possible. If left and right do not exist, we are at a leaf node and need
    // to record the value.
    //
    // If prev is left child of curr, we are going up the tree from the left.
    // Since prev is the left child, we are at a "parent" node. Hence, we want
    // to print the right child before the parent. Therefore, we try to push the
    // right child if it is available, otherwise we record this value.
    //
    // If prev is right child of curr, we are going up the tree from the right.
    // In this case, we are already going "back", so we always record the value.
    vector<int> res;
    stack<TreeNode*> to_visit;
    if (root) to_visit.push(root);
    TreeNode* prev = NULL;

    while (!to_visit.empty()) {
      TreeNode* curr = to_visit.top();
      // prev is parent of curr
      if (!prev || prev->left == curr || prev->right == curr) {
        if (curr->left) {
          to_visit.push(curr->left);
        } else if (curr->right) {
          to_visit.push(curr->right);
        } else {
          res.push_back(curr->val);
          to_visit.pop();
        }
        // prev is left child of curr, so we are going up tree from left
      } else if (curr->left == prev) {
        if (curr->right) {
          to_visit.push(curr->right);
        } else {
          res.push_back(curr->val);
          to_visit.pop();
        }
        // prev is right child of curr, so we are going up tree from right
      } else {
        res.push_back(curr->val);
        to_visit.pop();
      }
      prev = curr;
    }

    return res;
  }
};
