class Solution {
public:
    int countSubstrings(string s) {
      int n,left,right,center,res;
      n=s.size();
      res = 0;

      for (center = 0; center < 2*n-1; ++center) {
        left = center / 2;
        right = left + center % 2;
        while (left >= 0 && right < n && s[left] == s[right]) {
          --left;
          ++right;
          res++;
        }
      }
      return res;
    }
};
