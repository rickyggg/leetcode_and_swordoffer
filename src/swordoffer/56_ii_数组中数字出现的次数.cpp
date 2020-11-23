class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = -1;
        for (const int i : nums)
            ++m[i];
        for (const int i : nums)
            if (m[i] == 1)
                res = i;
        return res;
    }
};
