#include <bits/stdc++.h>
using namespace std;
class TrieNode {
  int val;
  TrieNode* binary[2];

  public:
  TrieNode()
  {
    binary[0] = binary[1] = NULL;
  }

  ~TrieNode()
  {
    if (binary[0])
      delete (binary[0]);
    if (binary[1])
      delete (binary[1]);
  }

  void insert(int n)
  {
    TrieNode* curr = this;
    for (int i = 30; i >= 0; i--) {
      bool bit = n & (1 << i);
      // cout<<bit<<endl;
      if (!(curr->binary[bit]))
        curr->binary[bit] = new TrieNode();
      curr = curr->binary[bit];
    }
    curr->val = n;
  }

  int getOpposite(int n)
  {
    TrieNode* curr = this;
    for (int i = 30; i >= 0; i--) {
      bool bit = n & (1 << i);
      if (curr->binary[!bit])
        curr = curr->binary[!bit];
      else
        curr = curr->binary[bit];
    }
    return curr->val;
  }
};

class Solution {
  public:
  int findMaximumXOR(vector<int>& nums)
  {
    TrieNode* root = new TrieNode();
    for (int n : nums)
      root->insert(n);
    int res = 0;
    for (int n : nums)
      res = max(res, n ^ root->getOpposite(n));
    return res;
  }
};
