class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int len = nums.size();
    int dp[len];
    memset(dp, 0, sizeof(dp));
    dp[0] = nums[0];
    int max_num = nums[0];
    for (int i = 1; i < len; ++i) {
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
      max_num = max(dp[i], max_num);
    }
    return max_num;
  }
};
