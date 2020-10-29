class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> m;
    for (const auto &i : nums)
      m[i]++;
    vector<int> res;
    priority_queue<pair<int, int>> pq;
    for (auto it = m.begin(); it != m.end(); ++it) {
      pq.push(make_pair(it->second, it->first));
      if (pq.size() > m.size() - k) {
        res.push_back(pq.top().second);
        pq.pop();
      }
    }
    return res;
  }
};
