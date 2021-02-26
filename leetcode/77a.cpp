class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
      if (n < k) return res;
      vector<int> cur;
      backtrack(cur, 0, n, n);
      return res;
    }
private:
    vector<vector<int>> res;
    void backtrack(vector<int> cur, int start, int n, int k) {
      if (k == 0) {
        res.push_back(cur);
        return;
      }

      for (int i = start; i < n; ++i) {
        cur.push_back(i+1);
        backtrack(cur, i+1, n, k-1);
        cur.pop_back();
      }
    }

};
