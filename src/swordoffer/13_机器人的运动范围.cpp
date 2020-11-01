class Solution {
public:
    int movingCount(int m, int n, int k) {
        if (!k) return 1;
        vector<int> visited(m * n, 0);
        int cnt = 0;
        backtrack(cnt, m, n, 0, 0, k, visited);
        return cnt;
    }
    void backtrack(int &cnt, int m, int n, int x, int y, int k, vector<int> &visited) {
        if (x >= m || y >= n || GetSum(x) + GetSum(y) > k)
            return;
        if (!visited[x * n + y]){
            ++cnt;
            visited[x * n + y] = 1;
            backtrack(cnt, m, n, x + 1, y, k, visited);
            backtrack(cnt, m, n, x, y + 1, k, visited);
        }
        return;
    }
    int GetSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
