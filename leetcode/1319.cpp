#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

      if (connections.size() < n-1) return -1;
      int i, res;
      vector<vector<int>> adj(n);
      vector<bool> seen(n);

      for (vector<int> &v: connections) {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
      }

      res = 0;
      for (i = 0; i < n; ++i) {
        if (!seen[i]) {
          dfs(adj, seen, i);
          ++res;
        }
      }

      return res-1;
    }

private:
    void dfs(vector<vector<int>> &adj, vector<bool>& seen, int node) {
      if (seen[node]) return;
      seen[node] = true;
      for (auto e: adj[node])dfs(adj, seen, e);
    }
};
