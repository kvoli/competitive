#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  bool canConvert(string str1, string str2)
  {
    int n, i;
    unordered_map<char, char> seen;
    if (str1 == str2)
      return true;

    n = str1.size();

    for (i = 0; i < n; ++i) {
      char c1 = str1[i], c2 = str2[i];
      if (seen.find(c1) != seen.end() && seen[c1] != c2)
        return false;
      seen[c1] = c2;
    }

    set<char> t(str2.begin(), str2.end());
    return t.size() < 26;
  }
};
