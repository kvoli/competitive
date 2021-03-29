#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  string removeDuplicates(string S)
  {
    deque<char> stk;

    for (auto const& c : S) {
      if (!stk.empty() && stk.back() == c) {
        stk.pop_back();
      } else {
        stk.push_back(c);
      }
    }

    string ret = "";

    while (stk.size()) {
      ret += (stk.front());
      stk.pop_front();
    }

    return ret;
  }
};
