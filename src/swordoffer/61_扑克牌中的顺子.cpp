class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count_0 = 0;
        for (int i = 0; i < nums.size() && nums[i] == 0; ++i)
            ++count_0;
        int left = count_0, right = count_0 + 1;
        int count_gap = 0;
        while (right < nums.size()) {
            if (nums[left] == nums[right])
                return false;
            count_gap += nums[right] - nums[left] - 1;
            ++left, ++right;
        }
        return (count_gap > count_0) ? false : true;
    }
};
