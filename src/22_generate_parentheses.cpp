class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    backtrack(res, "", n, 0);
    return res;
  }
  void backtrack(vector<string> &res, string str, int n, int m) {
    if (!n && !m) {
      res.push_back(str);
      return;
    }
    if (m > 0)
      backtrack(res, str + ")", n, m - 1);
    if (n > 0)
      backtrack(res, str + "(", n - 1, m + 1);
  }
};
