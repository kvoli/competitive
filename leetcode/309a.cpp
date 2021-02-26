
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int prev_buy,prev_sell(0),buy(INT_MIN),sell(0);

      for (auto p: prices) {
        prev_buy = buy;
        buy = max(prev_sell - p, buy);
        prev_sell = sell;
        sell = max(prev_buy + p, sell);
      }
      return sell;
    }
};
