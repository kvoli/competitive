class Solution {
  public:
  int numberOfMatches(int n)
  {

    int i = 0;
    while (n != 1) {
      i += n / 2;
      n -= n / 2;
    }

    return i;
  }
};
