class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        for (char &c : p) ++need[c];
        int left = 0, right = 0;
        int valid = 0;
        vector<int> res;
        while (right < s.size()) {
            char r = s[right++];
            if (need.count(r)) {
                ++window[r];
                if (window[r] == need[r])
                    ++valid;
            }
            while (right - left >= p.size()) {
                if (valid == need.size())
                    res.push_back(left);
                char l = s[left++];
                if (need.count(l)) {
                    if (window[l] == need[l])
                        --valid;
                    --window[l];
                }
            }
        }
        return res;
    }
};
