#include <bits/stdc++.h>
using namespace std;
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
    int pathSum(TreeNode* root, int sum) {
      res = 0;
      unordered_map<int,int> mp;
      mp[0] = 1;
      solve(root, sum, 0, mp);
      return res;
    }
private:
    int res;
    void solve(TreeNode* root, int target, int cur, unordered_map<int,int>& mp) {
      if (!root) return;
      cur += root -> val;
      res += mp[cur-target];
      mp[cur] += 1;

      solve(root -> left, target, cur, mp);
      solve(root -> right, target, cur, mp);

      mp[cur] -=1;
      cur-= root -> val;
    }
};
