class Solution {
public:
  int calculate(string s) {
    int total = 0;
    vector<int> signs(2, 1);
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] >= '0') {
        int number = 0;
        while (i < s.size() && s[i] >= '0')
          number = 10 * number + (s[i++] - '0');
        total += signs.back() * number;
        signs.pop_back();
        --i;
      } else if (s[i] == ')') {
        signs.pop_back();
      } else if (s[i] != ' ') {
        signs.push_back(signs.back() * (s[i] == '-' ? -1 : 1));
      }
    }
    return total;
  }
};
