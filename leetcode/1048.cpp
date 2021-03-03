#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestStrChain(vector<string>& words) {
      unordered_map<string, int> mp;
      int res, cur, i;
      sort(words.begin(), words.end(), [](const auto& a, const auto& b){return a.size() < b.size();});

      cur = res = 0;
      
      for (auto s: words) {
        for (i = 0; i < (int)s.length(); ++i) {
          string pre = s.substr(0, i) + s.substr(i+1);
          mp[s] = max(mp[s], mp.find(pre) == mp.end() ? 1 : mp[pre] + 1);
        }
        res = max(res, mp[s]);
      }
      return res;
    }
};
