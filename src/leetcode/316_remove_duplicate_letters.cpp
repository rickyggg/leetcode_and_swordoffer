class Solution {
public:
  string removeDuplicateLetters(string s) {
    unordered_map<char, int> m;
    unordered_map<char, int> visited;
    string result = "";
    for (const char &c : s)
      ++m[c];
    for (const char &c : s) {
      --m[c];
      if (visited[c])
        continue;
      while (!result.empty() && c < result.back() && m[result.back()] > 0) {
        visited[result.back()] = false;
        result.pop_back();
      }
      result.push_back(c);
      visited[c] = true;
    }
    return result;
  }
};
