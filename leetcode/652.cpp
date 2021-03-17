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
  // if its a leaf node and there is another leaf with same val
  // LR
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
  {
    unordered_map<string, vector<TreeNode*>> mp;
    serialize(root, mp);

    vector<TreeNode*> res;
    for (auto& it : mp) {
      if (it.second.size() > 1)
        res.push_back(it.second[0]);
    }
    return res;
  }

  private:
  string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& mp)
  {
    if (!node)
      return "";
    string s = "(" + serialize(node->left, mp) + to_string(node->val) + serialize(node->right, mp) + ")";
    mp[s].push_back(node);
    return s;
  }
};
