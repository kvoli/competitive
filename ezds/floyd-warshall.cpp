#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

      int i,j,K;
      K = k;
      vector<vector<int>> dist(n, vector<int> (n, INT_MAX));
      for (i = 0; i < n; ++i) dist[i][i] = 0;
      for (auto e: times) dist[e[0]-1][e[1]-1] = e[2];

      for (k = 0; k < n; ++k) 
        for (i = 0; i < n; ++i) 
          for (j = 0; j < n; ++j)
            if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

      int res = 0;
      for (i = 0; i < n; ++i) res = max(res, dist[K-1][i]);
      return res == INT_MAX ? -1 : res;
    }
};
