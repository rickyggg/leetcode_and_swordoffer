class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1 || n == 0) return 1;
        double res = 1;
        long num = n;
        if (n < 0) {
            num = -num;
            x = 1 / x;
        }
        while (num) {
            if (num & 0x1) res *= x;
            x *= x;
            num >>= 1;
        }
        return res;
    }
};
