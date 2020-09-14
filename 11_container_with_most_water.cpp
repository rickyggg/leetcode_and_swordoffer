class Solution {
public:
  int maxArea(vector<int> &height) {
    int first = 0, second = height.size() - 1;
    int volume = 0, max = 0;
    while (first < second) {
      if (height[first] < height[second]) {
        volume = height[first] * (second - first);
        ++first;
      } else {
        volume = height[second] * (second - first);
        --second;
      }
      if (volume > max)
        max = volume;
    }
    return max;
  }
};
