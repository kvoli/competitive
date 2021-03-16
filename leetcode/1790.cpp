class Solution {
  public:
  bool areAlmostEqual(string s1, string s2)
  {
    int diff = 0;
    int idx = 0;

    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i]) {
        ++diff;
        if (diff > 1) {
          if (s1[idx] != s2[i] || s1[i] != s2[idx])
            return false;
        }
        idx = i;
      }
    }
    return diff == 0 || diff == 2;
  }
};
