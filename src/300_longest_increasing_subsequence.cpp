class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    const int n = nums.size();
    if (n < 1)
      return 0;
    int dp[n];
    fill(dp, dp + n, 1);
    int res = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j])
          dp[i] = max(dp[i], dp[j] + 1);
      }
      res = max(dp[i], res);
    }
    return res;
  }
};
