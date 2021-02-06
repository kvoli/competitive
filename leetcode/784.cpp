#include <bits/stdc++.h>

using namespace std;

class Solution {
  private:

    char invert(char s) {
      if (isupper(s)) {
        return tolower(s);
      }
      return toupper(s);
    }

    vector<string> solve(string S, int k) {
      vector<string> res;
      if (k == S.length()) {
        res.push_back("");
        return res;
      } 

      vector<string> res_minus_one = solve(S, k + 1);

      for (auto s: res_minus_one) {
        if (isalpha(S[k]))  {
          char a = S[k];
          char b = invert(S[k]);
          string Sa = string(1, a); Sa.append(s);
          string Sb = string(1, b); Sb.append(s);
          res.push_back(Sa);
          res.push_back(Sb);
        } else {
          string Sa = string(1, S[k]); Sa.append(s);
          res.push_back(Sa);
        }
      }
      return res;
    }

  public:
    vector<string> letterCasePermutation(string S) {
      vector<string> res;
      if (S.length() == 0) return res;
      return solve(S, 0);
    }
};
