class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();
    int k = (m + n) / 2;
    if ((m + n) % 2 == 0) {
      return (findKth(nums1, nums2, 0, 0, k) +
              findKth(nums1, nums2, 0, 0, k + 1)) /
             2.0;
    } else {
      return findKth(nums1, nums2, 0, 0, k + 1);
    }
  }

  int findKth(vector<int> &nums1, vector<int> &nums2, int i, int j, int k) {
    if (i >= nums1.size())
      return nums2[j + k - 1];
    if (j >= nums2.size())
      return nums1[i + k - 1];
    if (k == 1)
      return min(nums1[i], nums2[j]);
    int mid_val1 =
        (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
    int mid_val2 =
        (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
    if (mid_val1 < mid_val2) {
      return findKth(nums1, nums2, i + k / 2, j, k - k / 2);
    } else {
      return findKth(nums1, nums2, i, j + k / 2, k - k / 2);
    }
  }
};

