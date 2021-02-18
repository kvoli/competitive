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

    vector<vector<int>> levelOrder(TreeNode* root) {
      solve(root, 0);
      return res;
    }

private:
    vector<vector<int>> res;

    void solve(TreeNode* root, int depth){ 
      if (root == NULL) return;
      solve(root -> left, depth+1);
      while (res.size() <= depth)  res.push_back(vector<int>(0,0));
      res[depth].push_back(root -> val);
      solve(root -> right, depth+1);
    }
};
