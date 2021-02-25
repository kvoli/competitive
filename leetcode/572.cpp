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
    // t is in s
    bool isSubtree(TreeNode* s, TreeNode* t) {
      if (!t && !s) return true;
      if (!s || !t) return false;

      if (check(s, t)) 
        return true;

      return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

private:
    bool check(TreeNode* s, TreeNode* t) {
      if (!s && !t) return true;
      if (!s || !t) return false;
      return s -> val == t -> val && check(s->left, t->left) && check(s->right, t->right);
    }
};
