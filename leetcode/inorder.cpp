#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode()
      : val(0)
      , left(nullptr)
      , right(nullptr)
  {
  }
  TreeNode(int x)
      : val(x)
      , left(nullptr)
      , right(nullptr)
  {
  }
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x)
      , left(left)
      , right(right)
  {
  }
};

void inorder(TreeNode* root)
{

  stack<TreeNode*> todo;
  stack<TreeNode*> seen;

  TreeNode* cur;

  todo.push(root);

  while (!todo.empty() || cur != nullptr) {

    if (cur != nullptr) {
      todo.push(cur);
      cur = cur->left;
    } else {
      cur = todo.top();
      todo.pop();
      if (cur >= target)
        ;

      seen.push(cur);
      cur = cur->right;
    }
  }
}
