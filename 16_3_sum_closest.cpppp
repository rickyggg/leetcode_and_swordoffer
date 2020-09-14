class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int res = nums[0] + nums[1] + nums[2];
    int distance;
    for (int i = 0; i < n; ++i) {
      int first = i + 1;
      int second = n - 1;
      while (first < second) {
        int sum = nums[i] + nums[first] + nums[second];
        distance = sum - target;
        if (abs(distance) < abs(res - target)) {
          res = sum;
        }
        if (sum < target) {
          ++first;
        } else if (sum > target) {
          --second;
        } else if (sum == target) {
          return target;
        }
      }
    }
    return res;
  }
};
