#include <bits/stdc++.h>

using namespace std;

// 226
// [2,2,6]
// [1,2,3]
class Solution {
public:
    int numDecodings(string s) {
      int n, i, prev, cur, res;
      n = s.length();

      if (!n || s[0] == '0') return 0;
      res = 1;


      for (i = 1; i < n;++i) {
        cur = s[i] - '0';
        prev = s[i-1] - '0';
        
        if (cur > 0 && cur < 7 && prev > 0 && prev < 3) {
          res++;
        } else if (cur == 0 && prev == 0){
          return 0;
        } 
      }
      return res;
    }
};
