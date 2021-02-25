class Solution {
public:
    string longestPalindrome(string s) {
      int n,i,len1,len2,len,end,start;
      n = s.size();
      end = start = 0;

      for (i = 0; i < n; ++i) {
        len1 = expandCenter(s, i, i, n);
        len2 = expandCenter(s, i, i+1, n);
        len = max(len1,len2);
        if (len > end - start) {
          start = i - (len-1) / 2;
          end = i + len / 2;
        }
      }
      return s.substr(start, end-start+1);
    }
private:
    int expandCenter(string s, int l, int r, int n) {
      while (l >= 0 && r <= n-1 && s[l] == s[r]) --l,++r;
      return r-l-1;
    }
};
