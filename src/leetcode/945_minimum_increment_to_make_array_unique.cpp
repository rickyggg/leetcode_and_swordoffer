class Solution {
public:
  int minIncrementForUnique(vector<int> &A) {
    int res = 0, size = A.size();
    sort(A.begin(), A.end());
    for (int i = 1; i < size; ++i) {
      if (A[i - 1] >= A[i]) {
        res += A[i - 1] - A[i] + 1;
        A[i] = A[i - 1] + 1;
      }
    }
    return res;
  }
};
