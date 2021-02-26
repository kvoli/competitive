#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

      int v,u,w,res;
      vector<vector<pii>> adj(n+1);
      vector<int> dist(n+1, INT_MAX);
      priority_queue<pii, vector<pii>, greater<pii>> pq;

      for (const auto &t: times) adj[t[0]].emplace_back(t[1], t[2]);


      dists[k] = 0;
      pq.emplace(0, k);
      while(!pq.empty()) {
        pii p = pq.top(); pq.pop();
        u = p.second;
        for (auto& to: adj[u]) {
          v = to.first;
          w = to.second;
          if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            pq.emplace(dist[v], v);
          }
        }
      }

      res = *max_element(begin(dist)+1, end(dist));
      return ans == INT_MAX ? -1 : ans;
    }
};
