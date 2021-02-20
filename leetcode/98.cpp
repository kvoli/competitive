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
    bool isValidBST(TreeNode* root) {
      return solve(root, numeric_limits<long>::min(), numeric_limits<long>::max());

    }
private:
    bool solve(TreeNode* root, long lower, long upper) {
      if (!root) return true;
      if (root -> val <= lower || root -> val >= upper) return false;
      return solve(root -> left, lower, root -> val) && solve(root -> right, root -> val, upper);

    }
};
