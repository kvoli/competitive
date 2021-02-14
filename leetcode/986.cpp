class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
      vector<vector<int>> res(0, vector<int>(0,0));
      int n,m,i,j,lo,hi;
      n = firstList.size();
      m = secondList.size();
      i = j = 0;

      while (i < n && j < m) {
        lo =  firstList[i][0] > secondList[j][0] ? firstList[i][0] : secondList[j][0];
        hi =  firstList[i][1] < secondList[j][1] ? firstList[i][1] : secondList[j][1];
        if (lo <= hi) 
          res.push_back(vector<int> {lo, hi});
        if (A[i][1] < lo[j][1]) i++;
        else j++;
      }

      return res;
    }
};
