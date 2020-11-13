/*
class Solution {
public:
  int longestValidParentheses(string s) {
    int n = s.size();
    if (!n || n < 2)
      return 0;
    int max_len = 0;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        st.pop();
        if (st.empty())
          st.push(i);
        else
          max_len = max(max_len, i - st.top());
      }
    }
    return max_len;
  }
};
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] > 2 ? dp[i - dp[i - 1] - 2]
                    : 0);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
