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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      vector<vector<int>> res(0, vector<int>(0,0));
      vector<int> cur;
      solve(root, targetSum, cur, res);
      return res;
    }

private: 
    void solve(TreeNode* root, int targetSum, vector<int>& cur, vector<vector<int>>& res) {
      if (!root) return;

      cur.push_back(root -> val);
      targetSum -= root -> val;

      if (!root -> left && !root->right && !targetSum) res.push_back(cur);
      
      if (root -> left) solve(root -> left, targetSum, cur, res);
      if (root -> right) solve(root -> right, targetSum, cur, res);

      cur.pop_back();
      targetSum += root -> val;
    }
};
