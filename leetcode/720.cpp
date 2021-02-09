#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
      string res = "";
      unordered_set<string> seen;
      sort(words.begin(), words.end());

      for (string word : words) {
        if (word.size() == 1 || seen.count(word.substr(0, word.size() - 1))) {
          res = word.size() > res.size() ? word : res;
          seen.insert(word);
        }
      }
      return res;
    }
};
