class Solution {
public:
  int minSubArrayLen(int s, vector<int> &nums) {
    int first = 0, second = 0;
    int n = nums.size();
    int sum = 0, len = __INT32_MAX__;
    while (second < n) {
      sum += nums[second++];
      while (sum >= s) {
        len = min(len, second - first);
        sum -= nums[first++];
      }
    }
    return len == __INT32_MAX__ ? 0 : len;
  }
};
