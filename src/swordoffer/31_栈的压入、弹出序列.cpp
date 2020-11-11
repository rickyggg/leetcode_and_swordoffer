class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int current = 0;
        int n = pushed.size();
        for (int i = 0; i < n; ++i) {
            s.push(pushed[i]);
            while (!s.empty() && s.top() == popped[current]) {
                s.pop();
                ++current;
            }
        }
        if (current == n)
            return true;
        else
            return false;
    }
};
