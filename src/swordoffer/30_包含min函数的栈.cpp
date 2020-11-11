class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        data.push(x);
        if (min_data.empty() || x <= min_data.top())
            min_data.push(x);
    }
    
    void pop() {
        if (!data.empty()){
            if (min_data.top() == data.top())
              min_data.pop();
            data.pop();
        }
    }
    
    int top() {
        return data.top();
    }
    
    int min() {
        return min_data.top();
    }

private:
    stack<int> data;
    stack<int> min_data;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
