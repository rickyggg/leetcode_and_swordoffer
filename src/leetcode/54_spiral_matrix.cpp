class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size();
    if (!m)
      return vector<int>{};
    int n = matrix[0].size();
    if (!n)
      return vector<int>{};
    vector<int> res(m * n);
    int u = 0, d = m - 1, l = 0, r = n - 1, p = 0;
    while (u <= d && l <= r) {
      for (int col = l; col <= r; ++col)
        res[p++] = matrix[u][col];
      if (++u > d)
        break;
      for (int row = u; row <= d; ++row)
        res[p++] = matrix[row][r];
      if (--r < l)
        break;
      for (int col = r; col >= l; --col)
        res[p++] = matrix[d][col];
      if (--d < u)
        break;
      for (int row = d; row >= u; --row)
        res[p++] = matrix[row][l];
      if (++l > r)
        break;
    }
    return res;
  }
};
