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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      dfs(root, p, q);
      return res;
    }
private:
    TreeNode* res;
    int dfs(TreeNode* root,  TreeNode* p, TreeNode* q) {
      int seen = 0, left, right;
      if (!root) return seen;

      left = dfs(root -> left, p, q);
      if (left > 1) return left;
      right = dfs(root -> right, p, q);
      if (right > 1) return right;
      seen = left + right;
      

      if (root -> val == p -> val || root -> val == q -> val) seen++;

      if (seen == 2) res = root;

      return seen;
    }

};
