class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() < k) return {};
        vector<int> res;
        deque<int> tem;     
        for (int i = 0; i < nums.size(); ++i) {
            while (!tem.empty() && nums[i] > nums[tem.back()]) {
                tem.pop_back();
            }
            if (!tem.empty() && tem.front() < i + 1 - k) tem.pop_front();
            tem.push_back(i);
            if (i + 1 >= k) res.push_back(nums[tem.front()]);
        }
        return res;
    }
};
