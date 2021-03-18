#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int wordsTyping(vector<string>& sentence, int rows, int cols)
  {
    unordered_map<int, int> mp;
    int i, num, start, n, j, cnt, len;

    num = 0;
    n = sentence.size();

    for (i = 0; i < rows; i++) {
      start = num % n;

      if (mp.count(start) == 0) {
        // we need to see how many words can fit given we start w/ this word
        cnt = 0;
        len = 0;
        for (j = start; len < cols; j = (j + 1) % n, cnt++) {
          // we've exceeded the length
          if (len + sentence[j].size() > cols)
            break;
          len += sentence[j].size() + 1;
        }

        // how many words we can fit on this word, starting with sentence[start]
        num += cnt;
        mp.emplace(start, cnt);
      } else
        // we already have the number of words that would fit
        num += mp[start];
    }
    return num / n;
  }
};
