class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        int size = min.size() + max.size();
        if ((size & 0x1) == 0) {
            if (!max.empty() && num < max[0]) {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
                num = max[0];
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        } else {
            if (!min.empty() && num > min[0]) {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }
    
    double findMedian() {
        int size = min.size() + max.size();
        if (size == 0) cerr<< "Empty" << endl;
        double median;
        if ((size & 0x1) == 1)
            median = min[0];
        else
            median = (max[0] + min[0]) / 2.0;
        return median;
    }

private:
    vector<int> min;
    vector<int> max;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
