class Solution {
public:
  vector<vector<int>> subsets(vector<int> &S) {
    vector<vector<int>> res(1, vector<int>());
    sort(S.begin(), S.end());
    for (int i = 0; i < S.size(); i++) {
      int n = res.size();
      for (int j = 0; j < n; j++) {
        res.push_back(res[j]);
        res.back().push_back(S[i]);
      }
    }
    return res;
  }
};
