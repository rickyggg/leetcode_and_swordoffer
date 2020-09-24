class Solution {
private:
  struct HeapStruct {
    int size;
    int *element;
  };

public:
  int findKthLargest(vector<int> &nums, int k) {
    // Heap O(nlogn)
    int n = nums.size();
    HeapStruct *h = new HeapStruct;
    h->element = new int[n + 1];
    h->size = 0;
    h->element[0] = INT_MAX; //sentinel
    for (int i = 0; i < n; ++i) {
      Insert(nums[i], h);
    }
    for (int i = 1; i < k; ++i) {
      DeleteMax(h);
    }
    return h->element[1];
  }
  void Insert(int x, HeapStruct *h) {
    int i;
    for (i = ++h->size; h->element[i / 2] < x; i /= 2)
      h->element[i] = h->element[i / 2];
    h->element[i] = x;
  }
  void DeleteMax(HeapStruct *h) {
    int i, child;
    int max, last;
    if (h->size == 0) {
      return;
    }
    max = h->element[1];
    last = h->element[h->size--];
    for (i = 1; i * 2 <= h->size; i = child) {
      child = i * 2;//left_child
      if (child != h->size && h->element[child + 1] > h->element[child])
        ++child;//right_child
      if (last < h->element[child])
        h->element[i] = h->element[child];
      else
        break;
    }
    h->element[i] = last;
  }
};
/* use_priority_queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
*/
