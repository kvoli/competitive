class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      graph g = buildGraph(numCourses, prerequisites);
      vector<int> order;
      vector<bool> todo(numCourses, false), done(numCourses, false);
      for (int i = 0; i < numCourses; ++i) {
        if (!done[i] && !acylic(g, todo, done, i, order)) return {}
      }
      reverse(order.begin(), order.end());
      return order;
    }

private:
  typedef vector<vector<int>> graph;

  graph buildGraph(int numCourses, vector<vector<int>>&  prerequisites) {
      graph g(numCourses);
      for (auto p: prerequisites) g[p[1]].push_back(p[0]);
      return g;
    }

    bool acylic(graph& g, vector<bool>& todo, vector<bool>& done, int node, vector<int>& order) {
      if (todo[node]) return false;
      if (done[node]) return true;
      todo[node] = done[node] = true;
      for (int v: g[node]) {
        if (!acylic(g, todo, done, v)) return false;
      }
      
      order.push_back(node);
      todo[node] = false;
      return true;
    }
};

