#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

      int i, left;
      if (n < 2){
        vector<int> res;
        for (i = 0; i < n; ++i) res.push_back(i);
        return res;
      }

      vector<int> leaves;
      graph g = makeGraph(n, edges);

      for (i = 0; i < n; ++i)  if (g[i].size() == 1) leaves.push_back(i); 

      left = n;
      while (n > 2) {
        vector<int> newLeaves;
        left -= leaves.size();
        for (auto leaf : leaves) {
          int next = *(g[leaf].begin());
          g[next].erase(leaf);
          if (g[next].size() == 1) newLeaves.push_back(next);
        }
        leaves = newLeaves;
      }
      return leaves;
    }


private:
    typedef vector<set<int>> graph;

    graph makeGraph(int n, vector<vector<int>>& edges) {
      graph g(n);
      for(auto edge: edges) {
        g[edge[0]].insert(edge[1]);
        g[edge[1]].insert(edge[0]);
      }
      return g;
    }
};
