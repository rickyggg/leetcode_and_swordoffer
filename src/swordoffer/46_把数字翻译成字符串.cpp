class Solution {
public:
    int translateNum(int num) {
        string num_string = to_string(num);
        return translateNum_to_string(num_string);
    }
    int translateNum_to_string(const string &num){
        int length = num.size();
        int *counts = new int[length];
        int count = 0;
        for (int i = length - 1; i >= 0; --i) {
            if (i < length - 1)
                count = counts[i + 1];
            else
                count = 1;
            if (i < length - 1) {
                int digit1 = num[i] - '0';
                int digit2 = num[i + 1] - '0';
                int converted = digit1 * 10 + digit2;
                if (converted >= 10 && converted <= 25) {
                    if (i < length - 2)
                        count += counts[i + 2];
                    else
                        count += 1;
                }
            }
            counts[i] = count;
        }
        count = counts[0];
        delete[] counts;
        return count;
    }
};
