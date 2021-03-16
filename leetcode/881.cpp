#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
  int numRescueBoats(vector<int>& people, int limit)
  {
    int n, i, j, k, res, carry;

    n = people.size();
    sort(begin(people), end(people));

    j = n - 1;
    i = res = carry = 0;
    while (i <= j) {
      if (people[i] + people[j] > limit) {
        --j;
      } else {
        ++i;
        --j;
      }
      ++res;
    };
    return res;
  }
};
// maximize the weight of each boat such that it is <= limit
