class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    backtrack(nums, 0);
    return res;
  }

private:
  vector<vector<int>> res;
  vector<int> temp;

  void backtrack(vector<int> &nums, int cur) {
    if (cur == nums.size()) {
      res.push_back(temp);
      return;
    }
    temp.push_back(nums[cur]);
    backtrack(nums, cur + 1);
    temp.pop_back();
    backtrack(nums, cur + 1);
  }
};
