class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        string str;
        istringstream ss(s);
        while (ss >> str) {
            stk.push(str);
            stk.push(" ");
        }
        if (!stk.empty()) stk.pop();
        s = "";
        while (!stk.empty()) {
            s += stk.top();
            stk.pop();
        } 
        return s;
    }
};
