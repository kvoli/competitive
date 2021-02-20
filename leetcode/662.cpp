class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        vector<int> lefts; // left most nodes at each level;
        int maxwidth = 0;
        dfs(root, 1, 0, lefts, maxwidth);
        return maxwidth;
    }
private:
    void dfs(TreeNode* node, int id, int depth, vector<int>& lefts, int& maxwidth) {
        if (!node) return;
        if (depth >= lefts.size()) lefts.push_back(id);  // add left most node
        maxwidth = max(maxwidth, id + 1 - lefts[depth]);
        dfs(node->left, id * 2, depth + 1, lefts, maxwidth);
        dfs(node->right, id * 2 + 1, depth + 1, lefts, maxwidth);
    }
};
