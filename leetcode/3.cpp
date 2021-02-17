#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char,int> count;

      for (auto c: s) count[c]=0;

      int l,r,n,res;

      n = s.length();

      l = r = res = 0;

      while (r < n) {
        if (count[s[r]] == 0) {
          count[s[r]]++;
          ++r;
        } else {
          count[s[l]]--;
          ++l;
        }
        res = max(res, r-l);
      }
      return res;
    }
};
