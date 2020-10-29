class Solution {
public:
  int splitArray(vector<int> &nums, int m) {
    int low = getMax(nums), high = getSum(nums);
    while (low <= high) {
      int mid = low + ((high - low) >> 1);// avoid int overflow (2^31-1)
      int n = split(nums, mid);
      if (n > m) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }
  int split(vector<int> &nums, int max) {
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (sum > max) {
        ++cnt;
        sum = nums[i];
      }
    }
    return cnt;
  }
  int getMax(vector<int> &nums) {
    int res = 0;
    for (const auto &n : nums)
      res = max(n, res);
    return res;
  }
  int getSum(vector<int> &nums) {
    int res = 0;
    for (const auto &n : nums)
      res += n;
    return res;
  }
};
