class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int slow = 0, fast = 0, n = nums.size();
    while (fast < n) {
      if (nums[slow] == nums[fast])
        ++fast;
      else
        nums[++slow] = nums[fast++];
    }
    return nums.empty() ? 0 : (slow + 1);
  }
};
