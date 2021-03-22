#include <bits/stdc++.h>

using namespace std;

class TreeAncestor {
  public:
  vector<vector<int>> p;
  TreeAncestor(int n, vector<int>& parent)
  {
    int i, j, k, cur;
    k = 20;

    p.resize(k, vector<int>(parent.size(), -1));

    // set initial (direct) parent 2^i, where i = 0
    for (i = 0; i < parent.size(); ++i)
      p[0][i] = parent[i];

    // set for 2^i, where i in [1,20)
    for (i = 1; i < k; ++i) {

      for (j = 0; j < parent.size(); ++j) {

        cur = p[i - 1][j];
        if (cur != -1)
          p[i][j] = p[i - 1][cur];
      }
    }
  }

  int getKthAncestor(int node, int k)
  {

    for (int i = 0; i < 20; ++i) {
      if (k & (1 << i)) {
        node = p[i][node];
        if (node == -1)
          return -1;
      }
    }
    return node;
  }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
