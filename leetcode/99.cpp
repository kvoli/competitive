#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode()
      : val(0)
      , left(nullptr)
      , right(nullptr)
  {
  }
  TreeNode(int x)
      : val(x)
      , left(nullptr)
      , right(nullptr)
  {
  }
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x)
      , left(left)
      , right(right)
  {
  }
};

typedef pair<TreeNode*, TreeNode*> pnn;

class Solution {

  public:
  TreeNode *x, *y, *pred;
  void recoverTree(TreeNode* root)
  {

    findInvariant(root);
    int tmp = x->val;
    x->val = y->val;
    y->val = tmp;
  }

  void findInvariant(TreeNode* root)
  {
    if (!root)
      return;
    TreeNode *left, *right;
    findInvariant(root->left);
    if (pred != nullptr && root->val < pred->val) {
      y = root;
      if (x == nullptr)
        x = pred;
      else
        return;
    }
    pred = root;
    findInvariant(root->right);
  }
};
