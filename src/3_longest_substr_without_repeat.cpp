class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<int> dict(127, -1);
    int max_len = 0, start = -1;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (dict[s[i]] > start)
        start = dict[s[i]];
      dict[s[i]] = i;
      max_len = max(max_len, i - start);
    }
    return max_len;
  }
};
