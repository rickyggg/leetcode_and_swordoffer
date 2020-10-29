class Solution {
public:
  int lower_bound(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }
  vector<int> searchRange(vector<int> &nums, int target) {
    int l = lower_bound(nums, target);
    int r = lower_bound(nums, target + 1) - 1;
    if (l < nums.size() && nums[l] == target)
      return {l, r};
    else
      return {-1, -1};
  }
};
