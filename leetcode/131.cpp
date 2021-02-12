#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> cur;
    void solve(int start, string s){ 
      if (start >= s.length()) res.push_back(cur);
      for (int end = start; end < s.length(); ++end)  {
        if (is_palindrome(s, start, end)) {
            cur.push_back(s.substr(start, end - start + 1));
            solve(end+1, s);
            cur.pop_back();
          }
      }
    }

    vector<vector<string>> partition(string s) {
      solve(0, s);
      return res;
    }

    int is_palindrome(string s, int low, int high) {
      while (low <= high && s[low] == s[high])  {
        low++;
        high--;
      }
      return low > high;
    }
};
