class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return -1;
        unordered_map<int, int> m;
        int n = nums.size() >> 1;
        for (int &i : nums) {
            ++m[i];
            if (m[i] > n)
                return i;
        }
        return -1;
    }
};
