class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    string prefix = "";
    int n = strs.size();
    if (n == 0)
      return prefix;
    for (int i = 0; i < strs[0].size(); ++i) {
      int j = 1;
      while (j < n && strs[j].size() > i) {
        if (strs[j][i] != strs[0][i])
          return prefix;
        ++j;
      }
      if (j == n)
        prefix += strs[0][i];
    }
    return prefix;
  }
};
