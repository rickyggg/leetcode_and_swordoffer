class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> cnt(1 << 10);
        cnt[0] = 1;
        long long res = 0;
        for (int i = 0, sum = 0; i < word.size(); i++) {
            sum ^= 1 << (word[i] - 'a');
            res += cnt[sum];
            for (int j = 0; j < 10; j++)
                res += cnt[sum ^ (1 << j)];
            cnt[sum]++;
        }
        return res;
    }
};
