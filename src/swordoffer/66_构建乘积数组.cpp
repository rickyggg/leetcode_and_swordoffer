class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> res(n, 1);
        int left = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = left;
            left = left * a[i];
        } 
        int right = 1;
        for (int i = n - 1; i >= 0; --i) {
            res[i] *= right;
            right *= a[i];
        }
        return res;
    }
};
