class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 1) return {};
        vector<int> res;
        int sum, left = 0, right = nums.size() - 1;
        while (left < right) {
            sum = nums[left] + nums[right];
            if (sum == target) {
                res.push_back(nums[left]);
                res.push_back(nums[right]);
                break;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        return res;
    }
};
