class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        for (const char &c : s) {
            if (c == ' ')
                ++cnt;
        }
        int p1 = s.size() - 1;
        s.resize(s.size() + 2 * cnt);
        int p2 = s.size() - 1;
        while (p1 >= 0) {
            if (s[p1] != ' ') {
                s[p2] = s[p1];
                --p1;
                --p2;
            } else {
                s.replace(p2 - 2,3,"%20");
                --p1;
                p2-=3;
            }
        }
        return s;
    }
};
