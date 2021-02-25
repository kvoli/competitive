class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      int n,i,j;
      n = s.size();
      unordered_set<string> mp(wordDict.begin(), wordDict.end());

      vector<int> dp(n+1, 0);
      dp[0] = true;
      for (i = 0; i <= n; ++i) {
        for (j = i-1; j >=0; --j) {
          if (dp[j]) {
            if (mp.find(s.substr(j, i-j)) != mp.end()) {
              dp[i]++;
              break;
            }
          }
        }
      }
      return dp[n];
    }
};
