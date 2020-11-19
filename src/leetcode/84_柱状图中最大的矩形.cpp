class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> s;
        heights.push_back(0); // 各个最大矩形在出栈计算，确保最矮的也计算到；
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int cur = s.top();
                s.pop();
                int wide = s.empty()? i : (i - s.top() - 1);
                res = max(res, wide * heights[cur]);
            }
            s.push(i);
        }
        return res;
    }
};
