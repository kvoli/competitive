class Solution {
  public:
  int maxProfit(vector<int>& prices)
  {
    int profit, price, n, i;
    profit = 0;
    price = prices[0];

    n = prices.size();

    for (i = 1; i < n; ++i) {
      if (prices[i] > price) {
        profit = max(profit, prices[i] - price);
      } else {
        price = min(price, prices[i]);
      }
    }
    return profit;
  }
};
