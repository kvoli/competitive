#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
      vector<int> cnt(26, 0);


      int n, l, r, res, freq;

      n = s.length();
      l = r = res =  freq = 0;


      for (; r < n; ++r) {
        cnt[s[r] - 'A']++;
        freq = max(freq, cnt[s[r] - 'A']);
        if ((r-l+1) - freq > k) {
          res = max(res, r-l);
          cnt[s[l] - 'A']--;
          l++;
        }
      }
      return max(res, r-l);
    }
};
