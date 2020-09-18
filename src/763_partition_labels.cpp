class Solution {
public:
  vector<int> partitionLabels(string S) {
    vector<int> res;
    int n = S.size(), start = 0, last = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < n; ++i)
      m[S[i]] = i;
    for (int i = 0; i < n; ++i) {
      last = max(last, m[S[i]]);
      if (i == last) {
        res.push_back(i - start + 1);
        start = i + 1;
      }
    }
    return res;
  }
};
