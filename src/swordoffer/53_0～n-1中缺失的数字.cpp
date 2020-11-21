class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (mid == nums[mid]) {
                left = mid + 1;
            } else {
                if (mid == 0 || nums[mid - 1] == mid - 1)
                    return mid;
                else 
                    right = mid - 1;
            }
        }
        return nums.size();
    }
};
