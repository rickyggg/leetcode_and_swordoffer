class Solution {
public:
    int strToInt(string str) {
        if (str.size() == 0) {
            g_nStatus = kInvalid;
            return 0;
        }
        int index = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ')
                index++;
            else
                break;
        }
        int result = 0;
        bool isNeg = false;
        if (str[index] == '-')
            isNeg = true;
        if (str[index] == '-' || str[index] == '+')
            index++;
        for (int i = index; i < str.size(); i++) {
            if (str[i] > '9' || str[i] < '0')
                break;
            int currNum = str[i] - '0';
            if (result > (INT_MAX / 10) || result * 10 > INT_MAX - currNum)
                return isNeg ? INT_MIN : INT_MAX;
            result = result * 10 + currNum;
        }
        return isNeg ? result * (-1) : result;
    }
private :
    enum Status {kValid = 0, kInvalid};
    int g_nStatus = kValid;
};
