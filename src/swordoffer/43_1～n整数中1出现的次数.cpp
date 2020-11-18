class Solution {
public:
    int countDigitOne(int n) {
        long long digit = 1, res = 0;
        while (n / digit) {
            long long high = n / (10 * digit);
            long long cur = (n / digit) % 10, low = n - (n / digit) * digit;
            if (cur == 0) {
                res += high * digit;
            } else if (cur == 1) {
                res += high * digit + low + 1;
            } else {
                res += (high + 1) * digit;
            }
            digit *= 10;
        }
        return res;
    }
};
