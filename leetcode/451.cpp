class Solution {
public:
    string frequencySort(string s) {

        
      vector<pair<int,char>> tmp;
      unordered_map<char,int> mp;
      for(auto c: s)mp[c]++;

      for(pair<char,int> p: mp)tmp.pushback(make_pair(p.second, p.first));

      sort(tmp.begin(), tmp.end());


      int pos = 0;
      for(int i = tmp.length()-1; i > -1; --i) {
        for(int j = 0; j < tmp[i].first; ++j) {
          s[pos] = tmp[i].second;
          ++pos;
        }
      }
      return s;
    }
};
