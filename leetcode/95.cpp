// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 95
// Title: Unique Binary Search Trees II
// Link: https://leetcode.com/problems/unique-binary-search-trees-ii
// Idea: See code comments.
// Difficulty: hard
// Tags: binary-tree, dynamic-programming
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
  // dp keeps track of a list of trees for given mn and mx values for the tree -
  // this way we don't have to reconstruct existing trees (and it's ok to reuse
  // them since we are ok with sharing memory here)
  //
  // construct trees by constructing ones with given mn and mx values - see each
  // tree as consisting of:
  //
  //                  i
  //         /                 \
  //  nodes in [mn,i)    nodes in (i, mx]
  //
  vector<TreeNode*> generateTrees(int mn, int mx,
                                  vector<vector<vector<TreeNode*>>>& dp) {
    if (mx < mn) return {nullptr};
    if (mn == mx) return {new TreeNode(mn)};
    if (dp[mn][mx].size() != 0) return dp[mn][mx];

    vector<TreeNode*>& result = dp[mn][mx];
    for (int i = mn; i <= mx; ++i) {
      vector<TreeNode*> left = generateTrees(mn, i - 1, dp);
      vector<TreeNode*> right = generateTrees(i + 1, mx, dp);
      for (TreeNode* L : left) {
        for (TreeNode* R : right) {
          result.push_back(new TreeNode(i));
          result.back()->left = L;
          result.back()->right = R;
        }
      }
    }
    return result;
  }

  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    vector<vector<vector<TreeNode*>>> dp(n + 1,
                                         vector<vector<TreeNode*>>(n + 1));
    return generateTrees(1, n, dp);
  }
};
