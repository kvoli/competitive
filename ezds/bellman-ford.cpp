class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

      int i,highest,j,u,v,w;
      vector<int> dist(INT_MAX, n);
      dist[k] = 0;

      for (i = 0; i < n; ++i) {
        for (j = 0; j < times.size(); ++j) {
          u = times[j][0];
          v = times[j][1];
          w = times[j][2];
          if (dist[u] != INT_MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
      }

      highest = 0;
      for(i = 1; i <= n; ++i) highest = max(highest, dist[i]);

      return highest != INT_MAX ? highest : -1;
    }
};
