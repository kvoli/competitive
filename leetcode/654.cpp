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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      return solve(nums, 0, nums.size()-1);
    }
private:
    TreeNode* solve(vector<int>& nums, int l, int r) {
      if (l > r) return NULL;
      int i = maxidx(nums, l, r);
      TreeNode* root = new TreeNode(nums[i]);
      root -> left = solve(nums, l, i-1);
      root -> right = solve(nums, i+1, r);
      return root;
    }

    int maxidx(vector<int>& nums, int l, int r){ 
      int res = l;
      for (int i = l; i < r+1; ++i)  res = nums[i] > nums[res] ? i : res;
      return res;
    }
};
