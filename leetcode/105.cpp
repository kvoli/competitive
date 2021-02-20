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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int n = preorder.size();
      return solve(preorder, inorder, {0, n-1}, {0, n-1});
    }
private:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, pair<int,int> pre, pair<int,int> in) {
      TreeNode* root = new TreeNode(preorder[pre.first]);
      if (pre.first == pre.second) return root;

      int i;
      for (i = 0; inorder[i] != root -> val; ++i);
      int diff = i - in.first;

      pair<int,int> pre_left = {pre.first + 1, pre.first + diff};
      pair<int,int> pre_right = {pre.first + diff + 1, pre.second};
      pair<int,int> in_left = {in.first, i-1};
      pair<int,int> in_right = {i+1, in.second};


      if (pre_left.second >= pre_left.first) root -> left = solve(preorder, inorder, pre_left, in_left);
      if (pre_right.second >= pre_right.first) root -> right = solve(preorder, inorder, pre_right, in_right);

      return root;
    }
};
