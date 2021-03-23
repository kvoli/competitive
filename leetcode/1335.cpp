#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
    int minDifficulty(vector<int>& jobDifficulty, int d)
    {
        int i, j, n, k, maxd;
        n = jobDifficulty.size();
        if (n < d)
            return -1;
        vector<int> dp(n + 1, 1e9);

        dp[n] = 0;
        for (k = 1; k <= d; ++k) {
            for (i = 0; i <= n - k; ++i) {
                maxd = 0;
                dp[i] = 1e9;
                for (j = i; j <= n - k; ++j) {
                    maxd = max(maxd, jobDifficulty[j]);
                    dp[i] = min(dp[i], dp[j + 1] + maxd);
                }
            }
        }
        return dp[0];
    }
};
