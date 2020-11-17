class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.size() == 0 || k == 0) return {};
        multiset<int, greater<int>> int_set;
        for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
            if (int_set.size() < k) {
                int_set.insert(*iter);
            } else {
                if (*iter < *int_set.begin()) {
                    int_set.erase(int_set.begin());
                    int_set.insert(*iter);
                }
            } 
        }
        vector<int> res(int_set.begin(), int_set.end());
        return res;

    }
    /*
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.size() == 0 || k == 0) return {};
        int start = 0, end = arr.size() - 1;
        int index = Partition(arr, start, end);
        while (index != k - 1) {
            if (index > k - 1) {
                end = index - 1;
                index = Partition(arr, start, end);
            } else {
                start = index + 1;
                index = Partition(arr, start, end);
            }
        }
        vector<int> res(arr.begin(), arr.begin() + k);
        return res;
    }
    int Partition(vector<int>& arr, int start, int end) {
        int pivot = arr[start];
        int i = start + 1, j = end;
        while (1) {
            while (i <= j && arr[i] <= pivot) ++i;
            while (i <= j && arr[j] >= pivot) --j;
            if (i > j) break;
            swap(arr[i], arr[j]);
        }
        swap(arr[j], arr[start]);
        return j;
    }
    */
};
