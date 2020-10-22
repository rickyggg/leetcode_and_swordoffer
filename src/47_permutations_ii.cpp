class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> temp;
    vector<int> visited(nums.size(), 0);
    sort(nums.begin(), nums.end());
    backtrack(nums, res, temp, visited);
    return res;
  }
  void backtrack(const vector<int> &nums, vector<vector<int>> &res,
                 vector<int> &temp, vector<int> &visited) {
    if (temp.size() == nums.size()) {
      res.push_back(temp);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (visited[i])
        continue;
      if (i && !visited[i - 1] && nums[i - 1] == nums[i])
        continue;
      temp.push_back(nums[i]);
      visited[i] = 1;
      backtrack(nums, res, temp, visited);
      temp.pop_back();
      visited[i] = 0;
    }
  }
};
