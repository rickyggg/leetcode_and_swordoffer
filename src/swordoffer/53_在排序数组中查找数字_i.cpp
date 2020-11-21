class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int res = 0;
        int first = GetFirst(nums, target);
        int last = GetLast(nums, target);
        if (first > -1 && last > -1)
            res = last - first + 1;
        return res;
    }
    int GetFirst(vector<int> &nums, int target){
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                if ((mid > 0 && nums[mid - 1] != target) || mid == 0)
                    return mid;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
    int GetLast(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                if ((mid < nums.size() - 1 && nums[mid + 1] != target) || mid == nums.size() - 1)
                    return mid;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};
