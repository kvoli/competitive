#include <bits/stdc++.h>

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
#define MAXX(a, b, c) ((a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c))
#define MINN(a, b, c) ((a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c))

using namespace std;

class Solution {
public:
    int expandCenter(string s, int l, int r, int n) {
      while (l >= 0 && r < n && s[l] == s[r]) {
        l--;
        r++;
      }
      return r-l-1;
    }
    string longestPalindrome(string s) {
      int n, i, start, end, len, len1, len2;
      n = s.length();
      start = end = 0;

      for (i = 0; i < n; ++i){
        len1 = expandCenter(s, i, i, n);
        len2 = expandCenter(s, i, i+1, n);
        len = MAX(len1, len2);
        if (len > end - start) {
          start = i - (len - 1) / 2;
          end = i + len / 2;
        }
      }
      return s.substr(start, end-start + 1);
    }
};
