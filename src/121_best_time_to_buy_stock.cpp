class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int n = prices.size();
    if (n < 2)
      return 0;
    int min_price = __INT32_MAX__, max_profit = 0;
    for (int i = 0; i < n; ++i) {
      min_price = min(min_price, prices[i]);
      max_profit = max(max_profit, prices[i] - min_price);
    }
    return max_profit;
  }
};
