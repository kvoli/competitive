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

#define MOD 1000000007

class Solution {
  public:
  vector<int> vals;

  int maxProduct(TreeNode* root)
  {
    long long res, total, cur;
    res = LONG_LONG_MIN;
    total = preorder(root);
    for (auto const& v : vals) {
      res = max(res, v * (total - v));
    }
    return (int)(res % MOD);
  }

  long long preorder(TreeNode* root)
  {
    if (!root)
      return 0;

    long long l, r, total;

    l = preorder(root->left);
    r = preorder(root->right);
    total = l + r + root->val;

    vals.push_back(total);

    return total;
  }
};
