class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3)
      return {};
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int target = -nums[i];
      if (target < 0)
        break;
      int first = i + 1;
      int second = n - 1;
      while (first < second) {
        int sum = nums[first] + nums[second];
        if (sum < target) {
          ++first;
        } else if (sum > target) {
          --second;
        } else {
          vector<int> triplets(3, 0);
          triplets[0] = nums[i];
          triplets[1] = nums[first];
          triplets[2] = nums[second];
          res.push_back(triplets);
          while (first < second && nums[first] == triplets[1])
            ++first;
          while (first < second && nums[second] == triplets[2])
            --second;
        }
      }
      while (i < n - 1 && nums[i + 1] == nums[i])
        ++i;
    }
    return res;
  }
};
