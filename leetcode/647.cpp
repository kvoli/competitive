#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {

      int left, right, n, center, res;
      n = s.length();
      res = 0;

      for (center = 0; center < 2 * n - 1; ++center) {
        left = center / 2;
        right = left + center % 2;
        while (left >= 0 && right < n && s[left] == s[right]) {
          res++;
          left--;
          right++;
        }
      }
      return res;
    }
};
