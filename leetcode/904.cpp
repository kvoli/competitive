class Solution {
public:
    int totalFruit(vector<int>& tree) {
      int n,res,l,r,first,second;
      n = tree.size();
      res = 0;

      first = tree[0];
      second = -1;
      l = r = 0;

      while (l < n && r < n) {

        if (tree[r] == first || tree[r] == second)
          ++r;
        else if (second == -1) {
          second = tree[r];
          ++r;
        } else {
          res = max(res, r-l);
          for (l = r-1; l > 0 && tree[l] == tree[r-1]; --l);
          l++;
          first = tree[r-1];
          second = tree[r];
        }
      }
      res = max(res, r-l);
      return res;
    }
};
