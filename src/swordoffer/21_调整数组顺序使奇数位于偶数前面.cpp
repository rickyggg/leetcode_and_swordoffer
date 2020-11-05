class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.empty()) return {};
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right && !IsEven(nums[left]))
                ++left;
            while (left < right && IsEven(nums[right]))
                --right;
            if (left < right)
                swap(nums[left], nums[right]);
        }
        return nums;
    }
    bool IsEven (int n) {
        return (n & 0x1) == 0;
    }
};
