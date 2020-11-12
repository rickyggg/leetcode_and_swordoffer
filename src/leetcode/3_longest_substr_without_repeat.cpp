class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> m;
    int left = 0, right = 0;
    int max_len = 0;
    while (right < s.size()) {
      char r = s[right++];
      ++m[r];
      while (m[r] > 1) {
        char l = s[left++];
        --m[l];
      }
      max_len = max(max_len, right - left);
    }
    return max_len;
  }
};