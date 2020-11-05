class Solution {
public:
  bool isNumber(string s) {
    // 1、从首尾寻找s中不为空格首尾位置，也就是去除首尾空格
    int i = s.find_first_not_of(' ');
    if (i == string::npos)
      return false;
    int j = s.find_last_not_of(' ');
    s = s.substr(i, j - i + 1);
    if (s.empty())
      return false;

    // 2、根据e来划分底数和指数
    int e = s.find('e');
    int E = s.find('E');

    // 3、指数为空，判断底数
    if (e == string::npos && E == string::npos)
      return JudgeRadix(s);
    // 4、指数不为空，判断底数和指数
    else if (E == string::npos)
      return JudgeRadix(s.substr(0, e)) && JudgeExponent(s.substr(e + 1));
    else
      return JudgeRadix(s.substr(0, E)) && JudgeExponent(s.substr(E + 1));
  }

  bool JudgeRadix(string s) { //判断底数是否合法
    bool result = false, point = false;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '+' || s[i] == '-') { //符号位不在第一位，返回false
        if (i != 0)
          return false;
      } else if (s[i] == '.') {
        if (point)
          return false; //有多个小数点，返回false
        else
          point = true;
      } else if (s[i] < '0' || s[i] > '9') { //非纯数字，返回false
        return false;
      } else {
        result = true;
      }
    }
    return result;
  }

  bool JudgeExponent(string s) {//判断指数是否合法
    bool result = false;
    //注意指数不能出现小数点，所以出现除符号位的非纯数字表示指数不合法
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '+' || s[i] == '-') { //符号位不在第一位，返回false
        if (i != 0)
          return false;
      } else if (s[i] < '0' || s[i] > '9') { //非纯数字，返回false
        return false;
      } else {
        result = true;
      }
    }
    return result;
  }
};
