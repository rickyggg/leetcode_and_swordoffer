class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (!row) return {};
        int col = matrix[0].size();
        if (!col) return {};
        vector<int> res(row * col);
        int u = 0, d = row - 1, l = 0, r = col - 1, p = 0;
        while (u <= d && l <= r){
            for (int j = l; j <= r; ++j)
                res[p++] = matrix[u][j];
            if (++u > d)
                break;
            for (int i = u; i <= d; ++i)
                res[p++] = matrix[i][r];
            if (--r < l)
                break;
            for (int j = r; j >= l; --j)
                res[p++] = matrix[d][j];
            if (--d < u)
                break;
            for (int i = d; i >= u; --i)
                res[p++] = matrix[i][l];
            if (++l > r)
                break;
        }
        return res;
    }
};
