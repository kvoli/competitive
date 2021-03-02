typedef pair<int,int> pii;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      int n,i,j,e,res;

      
      n = matrix.size();

      auto comp = [&matrix] (pii a, pii b) { return matrix[a.first][a.second] > matrix[b.first][b.second]; };
      priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);

      for (i = 0; i < n; ++i) pq.emplace(i, 0);

      while (k--) {
        i = pq.top().first;
        j = pq.top().second;
        res = e = matrix[i][j];
        pq.pop();
        if (j != n-1)
          pq.emplace(i, j+1);
      }
      return res;
    }
};
