#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void findSecretWord(vector<string>& wordlist, Master& master)
  {
    init(wordlist);
    int i, matched, size;
    string guess = wordlist[0];
    for (int i = 0; i < 10; ++i) {
      matched = master.guess(guess);
      //
      // we found it
      if (matched == 6)
        return;

      // find all (guess,matched) that exist
      vector<string> ret = mp[getkey(guess, matched)];

      cout << "Guess: " << guess << ", Matched: " << matched << endl;
      cout << "Current Candidates: " << endl;
      vector<string> c(candidates.begin(), candidates.end());
      showVector(c);

      // update our candidate set
      unordered_set<string> newCandidates;
      for (auto const& word : ret) {
        if (candidates.find(word) != candidates.end())
          newCandidates.insert(word);
      }
      candidates = newCandidates;

      cout << "Matched Strings" << endl;
      showVector(ret);
      cout << "resulting set" << endl;
      vector<string> d(candidates.begin(), candidates.end());
      showVector(d);
      cout << "new guess: " << *candidates.begin() << endl;

      // set our guess to be a candidate
      guess = *candidates.begin();
    }
  }

  private:
  unordered_map<string, vector<string>> mp;
  unordered_set<string> candidates;

  string getkey(string& word, int matched)
  {
    string key = word;
    key += "#";
    key += to_string(matched);
    return key;
  }

  void showVector(vector<string>& vec)
  {
    printf("[");
    for (int i = 0; i < vec.size() - 1; ++i)
      cout << vec[i] << ",";
    cout << vec[vec.size() - 1];
    printf("]\n");
  }

  void init(vector<string>& wordList)
  {
    int i, j, n, matched;
    n = wordList.size();
    string key;

    for (i = 0; i < n; ++i) {
      for (j = 0; j < n; ++j) {
        if (i != j) {
          matched = matches(wordList[i], wordList[j]);
          key = getkey(wordList[i], matched);
          if (mp.find(key) == mp.end()) {
            mp[getkey(wordList[i], matched)] = { wordList[j] };
          } else {
            mp[getkey(wordList[i], matched)].push_back(wordList[j]);
          }
        }
      }
      candidates.insert(wordList[i]);
    }
  }

  int matches(string& a, string& b)
  {
    int res, i;
    res = 0;
    for (i = 0; i < 6; ++i) {
      if (a[i] == b[i])
        ++res;
    }
    return res;
  }
};
