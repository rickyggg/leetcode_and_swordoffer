class Solution {
public:
  string longestPalindrome(string s) {
    int len = s.size();
    if (len < 2)
      return s;
    int dp[len][len];
    memset(dp, 0, sizeof(dp));
    int start = 0;
    int max_l = 1;
    for (int i = 0; i < len; ++i) {
      dp[i][i] = 1;
      if (i < len - 1 && s[i] == s[i + 1]) {
        dp[i][i + 1] = 1;
        start = i;
        max_l = 2;
      }
    }
    for (int l = 3; l <= len; l++) {
      for (int i = 0; i + l - 1 < len; ++i) {
        int j = i + l - 1;
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = 1;
          if (l > max_l) {
            start = i;
            max_l = l;
          }
        }
      }
    }
    return s.substr(start, max_l);
  }
};
