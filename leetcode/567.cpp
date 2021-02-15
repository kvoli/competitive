class Solution {
public:
    vector<int> ref;
    vector<int> cur;
    bool same() {
      for (int i = 0; i < 26; ++i) if (ref[i] != cur[i]) return false;
      return true;
    }

    bool checkInclusion(string s1, string s2) {
        
      int i,n1,n2;
      n1 = s1.length();
      n2 = s2.length();

      if (n1 > n2) return false;
    

      ref.resize(26, 0);
      cur.resize(26, 0);


      for(auto s: s1) ref[s - 'a']++;

      for (i = 0; i < n2; ++i) {
        cur[s2[i] - 'a']++;
        if (i + 1 >= n1) {
          if (same()) return true;
          cur[s2[i-n1+1] - 'a']--;
        }
      }
      return false;
    }
};
