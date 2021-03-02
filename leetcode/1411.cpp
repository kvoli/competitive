class Solution {
public:
    int numOfWays(int n) {
      long xyx1 = 6, xyz1 = 6, xyx2, xyz2, mod = (long)1e9 + 7;

      for (int i = 1; i < n; ++i) {
        xyx2 = xyx1 * 3 + xyz1 * 2;
        xyz2 = xyx1 * 2 + xyz1 * 2;
        xyx1 = xyx2 % mod;
        xyz1 = xyz2 % mod;
      }
      return (xyx1 + xyz1) % mod;
    }
};
