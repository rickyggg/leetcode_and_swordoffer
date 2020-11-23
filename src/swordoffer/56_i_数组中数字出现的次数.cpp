class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int s = 0;
        for (const int i : nums)
            s ^= i;
        s = s & (-s);
        vector<int> res(2, 0);
        for (const int i : nums) {
            if (i & s)
                res[0] ^= i;
            else    
                res[1] ^=i;
        }
        return res;
    }
};
