class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    stack<int> s;
    vector<int> res;
    unordered_map<int, int> m;
    for (const int & n : nums2) {
      while (!s.empty() && s.top() < n) {
        m[s.top()] = n;
        s.pop();
      }
      s.push(n);
    }
    for (const int &n : nums1)
        res.push_back(m.count(n) ? m[n] : -1);
    return res;
  }
};
