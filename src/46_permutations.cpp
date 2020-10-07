class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    vector<int> temp;
    int visited[nums.size()];
    memset(visited, 0, sizeof(visited));
    backtrack(nums, res, temp, visited, 0);
    return res;
  }
  void backtrack(const vector<int> &nums, vector<vector<int>> &res,
                 vector<int> &temp, int *visited, const int start) {
    if (temp.size() == nums.size()) {
      res.push_back(temp);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (!visited[i]) {
        temp.push_back(nums[i]);
        visited[i] = 1;
        backtrack(nums, res, temp, visited, 0);
        temp.pop_back();
        visited[i] = 0;
      }
    }
  }
};
