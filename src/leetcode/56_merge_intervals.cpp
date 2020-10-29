class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size();
    if (n < 2)
      return intervals;
    sort(intervals.begin(), intervals.end(),
         [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < n; ++i) {
      int curr_end = res.back()[1];
      int next_begin = intervals[i][0];
      int next_end = intervals[i][1];
      if (curr_end < next_begin)
        res.push_back(intervals[i]);
      else
        res.back()[1] = max(curr_end, next_end);
    }
    return res;
  }
};
