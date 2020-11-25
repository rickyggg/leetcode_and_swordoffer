class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        if (target < 3) return {};
        int mid = (target + 1) >> 1;
        int left = 1, right = 2;
        int sum = left + right;
        vector<vector<int>> res;
        while (left < mid) {
            if (sum == target) {
                res_push(res, left, right);
            } 
            while (sum > target && left < mid) {
                sum -= left;
                ++left;
                if (sum == target) {
                    res_push(res, left, right);
                }
            } 
            ++right;
            sum += right;
        }
        return res;
    }
    void res_push(vector<vector<int>> &res,int left, int right) {
        vector<int> tmp;
        for (int i = left; i <= right; ++i)
            tmp.push_back(i);
        res.push_back(tmp);
    }
};
