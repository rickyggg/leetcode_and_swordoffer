class Solution {
public:
  int reversePairs(vector<int> &nums) {
    int res = 0;
    vector<int> copy(nums.size(), 0);
    Mergesort(nums, 0, nums.size() - 1, copy, res);
    return res;
  }
  void Mergesort(vector<int> &nums, int l, int r, vector<int> &copy, int &res) {
    if (l >= r)
      return;
    int mid = l + ((r - l) >> 1);
    Mergesort(nums, l, mid, copy, res);
    Mergesort(nums, mid + 1, r, copy, res);
    int i = l, j = mid + 1, p = l;
    while (i <= mid && j <= r) {
      if (nums[j] < nums[i]) {
        copy[p++] = nums[j++];
        res += mid - i + 1;
      } else {
        copy[p++] = nums[i++];
      }
    }
    while (i <= mid) {
      copy[p++] = nums[i++];
    }
    while (j <= r) {
      copy[p++] = nums[j++];
    }
    while (l <= r) {
      nums[l] = copy[l];
      l++;
    }
  }
};
