class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> res;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    backtrack(temp, res, 0, target, candidates);
    return res;
  }
  void backtrack(vector<int> &temp, vector<vector<int>> &res, const int start,
                 const int target, const vector<int> &candidates) {
    if (target == 0) {
      res.push_back(temp);
      return;
    }
    for (int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
      if (i && candidates[i] == candidates[i - 1] && i > start)
        continue;
      temp.push_back(candidates[i]);
      backtrack(temp, res, i + 1, target - candidates[i], candidates);
      temp.pop_back();
    }
  }
};
