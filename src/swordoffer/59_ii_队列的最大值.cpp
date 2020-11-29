class MaxQueue {
public:
    MaxQueue() {
    }
    int max_value() {
        if (q_max.empty()) return -1;
        return q_max.front();
    }
    void push_back(int value) {
        while (!q_max.empty() && value > q_max.back())
            q_max.pop_back();
        q.push(value);
        q_max.push_back(value);
    }
    int pop_front() {
        if (q.empty()) return -1;
        int res = q.front();
        if (q_max.front() == q.front())
            q_max.pop_front();
        q.pop();
        return res;
    }

private:
    queue<int> q;
    deque<int> q_max;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
