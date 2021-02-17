/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt;
    int res;
    void solve(TreeNode *root, int k) {
      if (root == NULL) return;
      solve(root -> left, k);
      cnt++;
      if (cnt == k) res = root -> val;
      solve(root -> right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
      cnt = 0;
      res = 0;

      solve(root, k-1);

      return res;
    }
};
