class Solution {
public:
    vector<string> permutation(string s) {
        if (s.empty()) return {};
        vector<string> res;
        string tmp = "";
        vector<int> visited(s.size(), 0);
        sort(s.begin(), s.end());
        backtrack(s, res, visited, tmp);
        return res;
    }
    void backtrack(const string &s, vector<string> &res, vector<int> &visited, string &tmp) {
        if (s.size() == tmp.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < s.size(); ++i){
            if (visited[i]) continue;
            if (i > 0 && !visited[i - 1] && s[i - 1] == s[i]) continue;
            tmp += s[i];
            visited[i] = 1;
            backtrack(s, res, visited, tmp);
            tmp.pop_back();
            visited[i] = 0;
        }
    }
};
