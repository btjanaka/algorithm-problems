// Author: btjanaka (Bryon Tjanaka)
// Problem: (Leetcode) 94
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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;

    stack<TreeNode*> to_visit;
    if (root) to_visit.push(root);

    while (!to_visit.empty()) {
      TreeNode* curr = to_visit.top();
      to_visit.pop();

      // Go down as far left as possible - inorder will
      // always start with the leftmost node.
      // curr will be at the leftmost node after this.
      while (curr) {
        to_visit.push(curr);
        curr = curr->left;
      }

      // to_visit may be empty at the very end, after the last node has been
      // encountered
      if (!to_visit.size()) continue;

      // Record this leftmost node - as we empty the stack,
      // all these "leftmost nodes" will be accounted for
      curr = to_visit.top();
      to_visit.pop();
      res.push_back(curr->val);

      // Try to go right on the next round; in-order traversal
      // will cover left, center, then right. Essentially, this
      // statement ensures that as we go back up the tree,
      // we still cover the right nodes.
      //
      // Even if the right node is null, we still need to push it. This way, on
      // the next run through this loop, it will pass the while(curr) loop.
      // Normally, the while(curr) loop will push the curr back onto the stack
      // after popping it as it goes all the way down. However, since this
      // statement would make curr null, curr is not pushed back onto the stack.
      // Since curr is not on the stack after this, the next node to cover gets
      // covered. If we did not push this null value onto the stack, we would
      // instead travel left on that next node again, and we would repeat
      // ourselves infinitely. Thus, pushing the right node unconditionally
      // ensures the traversal terminates.
      to_visit.push(curr->right);
    }
    return res;
  }
};

// shortened version
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;

    stack<TreeNode*> to_visit;
    if (root) to_visit.push(root);

    while (!to_visit.empty()) {
      TreeNode* curr = to_visit.top();
      to_visit.pop();

      // Go down as far left as possible
      while (curr) {
        to_visit.push(curr);
        curr = curr->left;
      }

      if (!to_visit.size()) continue;  // to_visit may be empty at the end

      // record node
      curr = to_visit.top();
      to_visit.pop();
      res.push_back(curr->val);

      to_visit.push(curr->right);  // unconditionally push right node
    }
    return res;
  }
};
