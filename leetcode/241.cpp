#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
      vector<int> res;
      string st;
      for (int i = 0; i < input.size(); ++i) {
        if (input[i] < '0') {
          vector<int> res1, res2;
          st = input.substr(0, i);
          
          if (mp.count(st) != 0) res1 = mp[st];
          else res1 = diffWaysToCompute(st);

          st = input.substr(i+1);
          if (mp.count(st) != 0) res2 = mp[st];
          else res2 = diffWaysToCompute(st);

          for (auto n1: res1) {
            for (auto n2: res2) {
              if (input[i] == '+') res.push_back(n1+n2);
              if (input[i] == '-') res.push_back(n1-n2);
              if (input[i] == '*') res.push_back(n1*n2);
            }
          }
        }
      }
      if (res.empty())  res.push_back(stoi(input));
      return res;
    }
private:
    unordered_map<string, vector<int>> mp;
};
