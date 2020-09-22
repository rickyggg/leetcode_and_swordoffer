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
