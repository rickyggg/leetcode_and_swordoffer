class Solution {
public:
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries) {
    int m = nums.size(), n = queries.size();
    vector<int> res;

    vector<vector<int>> pre(m + 1, vector<int>(101, 0));
    for (int i = 1; i <= m; ++i) {
        pre[i] = pre[i - 1];
        pre[i][nums[i - 1]]++;
    }

    for (auto &q : queries) {
        int l = q[0], r = q[1];
        int last = 0, best = INT_MAX;
        for (int j = 1; j <= 100; j++) {
            if (pre[l][j] != pre[r + 1][j]) {
                if (last) {
                    best = min(best, j - last);
                }
                last = j;
            }
        }
        if (best == INT_MAX) {
            best = -1;
        }
        res.emplace_back(best);
    }

    return res;
}
};
