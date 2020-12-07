class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char &c : t) ++need[c];
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        while (right < s.size()) {
            char r = s[right++];
            if (need.count(r)) {
                ++window[r];
                if (window[r] == need[r])
                    ++valid;
            }
            while (valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                char l = s[left++];
                if (need.count(l)) {
                    if (window[l] == need[l])
                        --valid;
                    --window[l];
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
