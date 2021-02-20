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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
      find(root, target, K);
      return res;
    }

private:
    vector<int> res;
    int find(TreeNode* root, TreeNode* target, int k) {
      if (!root) return -1;

      if (root -> val == target -> val) {
        solve(root,  k);
        return 1;
      }

      int left, right;
      left = find(root -> left, target, k);
      right = find(root -> right, target, k);

      if (left > -1) {
        if (k - left == 0) res.push_back(root -> val);
        if (k - left > 0) solve(root -> right, k-left-1);
        return left + 1;
      }

      if (right > -1) {
        if (k - right == 0) res.push_back(root -> val);
        if (k - right > 0) solve(root -> left, k-right-1);
        return right + 1;
      }

      return -1;
    }

    void solve(TreeNode* root, int k) {
      if (!root || k < 0) return;

      if (!k){
       res.push_back(root -> val);
       return;
      }

      solve(root -> left, k-1);
      solve(root -> right, k-1);
    }
};
