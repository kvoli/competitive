#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  string reverseParentheses(string s)
  {
    int opened = 0, i, n = s.size();
    deque<char> stk;

    for (i = 0; i < n; ++i) {
      if (s[i] == ')') {
        string rev = "";
        while (stk.back() != '(') {
          rev += stk.back();
          stk.pop_back();
        }
        stk.pop_back();
        for (auto const& c : rev)
          stk.push_back(c);
      } else {
        stk.push_back(s[i]);
      }
    }

    string ret = "";
    while (!stk.empty()) {
      ret += stk.front();
      stk.pop_front();
    }
    return ret;
  }
};
