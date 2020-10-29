class MyQueue {
private:
  stack<int> input, output;

public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) { input.push(x); }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    int tmp = peek();
    output.pop();
    return tmp;
  }

  /** Get the front element. */
  int peek() {
    if (output.empty())
      while (input.size()) {
        output.push(input.top());
        input.pop();
      }
    return output.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return input.empty() && output.empty(); }
};
