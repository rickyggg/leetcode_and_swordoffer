class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string ans;
        for (int i = 0; i < nums.size(); ++i)
            strs.push_back(to_string(nums[i]));
        sort(strs.begin(), strs.end(), [](string& s1, string& s2){return s1 + s2 < s2 + s1;});
        for (int i = 0; i < strs.size(); ++i)
            ans += strs[i];
        return ans;
    }
};
