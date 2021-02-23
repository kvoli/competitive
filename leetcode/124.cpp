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
    int maxPathSum(TreeNode* root) {
      int res = INT_MIN;
      solve(root, &res);
      return res;
    }
private:
    int solve(TreeNode* root, int* res) {
      if (!root) return 0;

      int leftPath, rightPath, curMax;
      leftPath = solve(root->left, res);
      rightPath = solve(root->right, res);

      curMax = max({leftPath, rightPath, leftPath + rightPath, 0}) + root -> val;
      *res = max(curMax, *res);
      return max({leftPath, rightPath, 0}) + root->val;
    }
};
