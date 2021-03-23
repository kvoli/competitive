#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  vector<int> closestKValues(TreeNode* root, double target, int k)
  {
    deque<int> dq;
    inorder(root, dq, target, k);
    vector<int> res(dq.begin(), dq.end());
    return res;
  }

  void inorder(TreeNode* root, deque<int>& dq, double target, int k)
  {
    if (root == nullptr)
      return;

    inorder(root->left, dq, target, k);

    if (dq.size() == k) {
      if (abs(target - dq.front()) > abs(1.0 * root->val - target)) {
        dq.pop_front();
        dq.push_back(root->val);
      } else {
        return;
      }
    } else {
      dq.push_back(root->val);
    }
    inorder(root->right, dq, target, k);
  }
};
