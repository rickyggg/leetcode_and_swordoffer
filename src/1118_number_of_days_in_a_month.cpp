vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> res(T.size());
    stack<int> s; 
    for (int i = T.size() - 1; i >= 0; i--) {
        while (!s.empty() && T[s.top()] <= T[i]) {
            s.pop();
        }
        res[i] = s.empty() ? 0 : (s.top() - i); 
        s.push(i); 
    }
    return res;
}
