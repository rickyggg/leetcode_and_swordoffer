class Solution {
public:
  int addDigits(int num) {
    // xyz = 100x + 10y + z = 99x + 9y + x + y + z
    if (num % 9 != 0) {
      num %= 9;
    } else if (num && num % 9 == 0) {
      num = 9;
    }
    return num;
  }
};
