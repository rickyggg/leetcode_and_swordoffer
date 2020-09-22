class MinStack {
private:
  vector<int> data;
  vector<int> min_res;

public:
  /** initialize your data structure here. */
  MinStack() { min_res.push_back(INT_MAX); }

  void push(int x) {
    data.push_back(x);
    if (x < min_res.back())
      min_res.push_back(x);
    else
      min_res.push_back(min_res.back());
  }

  void pop() {
    data.pop_back();
    min_res.pop_back();
  }

  int top() { return data.back(); }

  int getMin() { return min_res.back(); }
};
