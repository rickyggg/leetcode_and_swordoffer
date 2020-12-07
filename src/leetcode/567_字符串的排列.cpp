class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char &c : s1) ++need[c];
        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char r = s2[right];
            ++right;
            if (need.count(r)) {
                ++window[r];
                if (window[r] == need[r])
                    ++valid;
            }
            while (right - left >= s1.size()) {
                if (valid == need.size())
                    return true;
                char l = s2[left];
                ++left;
                if (need.count(l)) {
                    if (window[l] == need[l])
                        --valid;
                    --window[l];
                }
            }
        }
        return false;
    }
};
