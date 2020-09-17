class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows <= 1)
      return s;
    int n = s.size();
    string *str = new string[numRows];
    int row = 0, step = 1;
    for (int i = 0; i < n; ++i) {
      str[row].push_back(s[i]);
      if (row == 0)
        step = 1;
      else if (row == numRows - 1)
        step = -1;
      row += step;
    }
    s.clear();
    for (int i = 0; i < numRows;++i){
        s.append(str[i]);
    }
    delete[] str;
    return s;
  }
};
