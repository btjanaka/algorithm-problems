// Author: btjanaka (Bryon Tjanaka)
// Problem: (Hackerrank) self-balancing-tree
// Title: Self Balancing Tree
// Link: https://www.hackerrank.com/challenges/self-balancing-tree/problem
// Idea: Implement AVL trees.
// Difficulty: medium
// Tags: binary-search-tree, implementation

/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

void calc_ht(node* root) {
  if (root == nullptr) return;
  int lh = root->left ? root->left->ht : -1;
  int rh = root->right ? root->right->ht : -1;
  root->ht = max(lh, rh) + 1;
}

node* insert(node* root, int val) {
  if (root == nullptr) {
    root = new node();
    root->val = val;
    root->left = root->right = nullptr;
    root->ht = 0;
  } else if (root->val == val) {
    // do nothing if already present
  } else {
    if (val > root->val) {
      root->right = insert(root->right, val);
    } else if (val < root->val) {
      root->left = insert(root->left, val);
    }

    int lh = root->left ? root->left->ht : -1;
    int rh = root->right ? root->right->ht : -1;

    // select rotation if necessary
    if (lh - rh > 1) {
      if (val > root->left->val) {
        // LR rotation
        node* tmp = root->left->right;
        root->left->right = tmp->left;
        node* tmp2 = root->left;
        root->left = tmp->right;
        tmp->left = tmp2;
        tmp->right = root;
        root = tmp;
      } else if (val < root->left->val) {
        // LL rotation
        node* tmp = root->left;
        root->left = tmp->right;
        tmp->right = root;
        root = tmp;
      }
    } else if (rh - lh > 1) {
      if (val > root->right->val) {
        // RR rotation
        node* tmp = root->right;
        root->right = tmp->left;
        tmp->left = root;
        root = tmp;
      } else if (val < root->right->val) {
        // RL rotation
        node* tmp = root->right->left;
        root->right->left = tmp->right;
        node* tmp2 = root->right;
        root->right = tmp->left;
        tmp->right = tmp2;
        tmp->left = root;
        root = tmp;
      }
    }
    calc_ht(root->left);
    calc_ht(root->right);
    calc_ht(root);
  }
  return root;
}
