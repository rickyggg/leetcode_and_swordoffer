class Solution {
public:
    char firstUniqChar(string s) {
        if (s.empty()) return ' ';
        unordered_map<char, int> m;
        for (const auto &c : s) 
            m[c]++;
        for (const auto &c : s) {
            if (m[c] == 1)
                return c;
        }
        return ' ';
    }   
};
