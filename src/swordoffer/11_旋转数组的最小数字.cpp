class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.size() == 0) throw std::invalid_argument("Invalid parameters");
        int left = 0, right = numbers.size() - 1;
        int cur = 0;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else if (numbers[mid] < numbers[left]) {
                right = mid - 1;
            } else {
                return InOrder(numbers);
            }
        }
        return numbers[left];
    }
    int InOrder(vector<int>& numbers) {
        int res = numbers[0];
        for (const auto &i : numbers) {
            if (i < res)
                res = i;
        }
        return res;
    }
};
