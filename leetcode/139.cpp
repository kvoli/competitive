class Solution {
public:
    bool solve(string s, unordered_set<string>& wordDict) {

      int n, i, j;
      string word;
      n = s.length();
      vector<bool> dp(n+1, false);
      dp[0] = true;
      for (i = 0; i <= n; ++i){
        for (j = i-1; j >= 0; --j) {
          if (dp[j]) {
            word = s.substr(j, i-j);
            if (wordDict.find(word) != wordDict.end()) {
              dp[i] = true;
              break;
            }
          }
        }
      }
      return dp[n];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> d(wordDict.begin(), wordDict.end());
        return solve(s, d);
    }
};
