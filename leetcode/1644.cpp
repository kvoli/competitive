#include <bits/stdc++.h>

using namespace std;

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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    lca(root, p, q);
    return res;
  }

  TreeNode* res = nullptr;
  bool lca(TreeNode* root, TreeNode* p, TreeNode* q)
  {
    if (!root)
      return false;

    int ret = 0;

    bool l = lca(root->left, p, q), r = lca(root->right, p, q);

    if (l)
      ret++;
    if (r)
      ret++;

    if (root == p)
      ret++;
    if (root == q)
      ret++;

    if (ret == 2)
      res = root;
    return ret > 0;
  }
};
