#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
  {
    adj.resize(n + 1);
    dfs.assign(n + 1, 0);
    low.assign(n + 1, 0);
    cur = 0;
    for (auto const& e : connections) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    visit(1, 0);

    return res;
  }

  private:
  vector<vector<int>> adj, res;
  vector<int> dfs, low;
  int cur;

  void visit(int vertex, int parent)
  {
    cur++;
    dfs[vertex] = cur;
    low[vertex] = cur;

    for (int nxt : adj[vertex]) {
      if (dfs[nxt] == 0) {
        visit(nxt, vertex);
        low[vertex] = min(low[vertex], low[nxt]);
        if (low[nxt] > dfs[vertex])
          res.push_back({ nxt, vertex });
      } else if (nxt != parent) {
        low[vertex] = min(low[vertex], dfs[nxt]);
      }
    }
  }
};
