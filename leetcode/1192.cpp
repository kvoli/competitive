class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
    }
private:
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& tin, vector<int>& low, int p = -1, int* timer) {
      visited[v] = true;
      tin[v] = low[v] = *timer++;
      for (int to: adj[v]) {

      }
      
    }
};
