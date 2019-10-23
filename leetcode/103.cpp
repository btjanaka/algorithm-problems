// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 103
// Title: Binary Tree Zigzag Level Order Traversal
// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Idea: BFS while keeping track of level
// Difficulty: medium
// Tags: tree, binary-tree
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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if (!root) return {};
    vector<vector<int>> res;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      TreeNode* cur;
      int lvl;
      tie(cur, lvl) = q.front();
      q.pop();
      if (cur->left) q.push({cur->left, lvl + 1});
      if (cur->right) q.push({cur->right, lvl + 1});
      if (lvl >= res.size()) res.push_back({});
      res[lvl].push_back(cur->val);
    }
    for (int i = 1; i < res.size(); i += 2) {
      for (int j = 0; j < res[i].size() / 2; ++j) {
        swap(res[i][j], res[i][res[i].size() - j - 1]);
      }
    }
    return res;
  }
};
