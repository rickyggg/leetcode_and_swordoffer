class Solution {
public:
  int findUnsortedSubarray(vector<int> &nums) {
    vector<int> *tmp = new vector<int>(nums);
    sort(tmp->begin(), tmp->end());
    int left = 0, right = nums.size() - 1;
    int flag = 0;
    while (left < right) {
      if (nums[left] == tmp->at(left))
        ++left;
      if (nums[right] == tmp->at(right))
        --right;
      if (nums[left] != tmp->at(left) && nums[right] != tmp->at(right)) {
        flag = 1;
        break;
      }
    }
    delete tmp;
    if (flag)
      return right - left + 1;
    else
      return 0;
  }
};
