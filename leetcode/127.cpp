#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> wset(wordList.begin(), wordList.end());
      queue<string> q;
      string cur;
      int res = 1;
        
    
      if (wset.find(endWord) == wset.end()) return 0;

      q.push(beginWord);

      while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
          cur = q.front(); q.pop();
          vector<string> next = genCandidates(cur);
          for (auto n: next) {
            if (n == endWord) return ++res;
            if (wset.find(n) != wset.end()) {
              q.push(n);
              wset.erase(n);
            }
          }
        }
       ++res;
      }
      return 0;
    }

private:
    vector<string> genCandidates(string s) {
      vector<string> candidates;
      for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < 26; ++j) {
          string cur = s;
          cur[i] = 'a' + j;
          candidates.push_back(cur);
        }
      }
      return candidates;
    }
};
