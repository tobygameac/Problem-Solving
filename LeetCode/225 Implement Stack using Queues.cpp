class Stack {
 
 public:
  
  // Push element x onto stack.
  void push(int x) {
    q_.push(x);
  }

  // Removes the element on top of the stack.
  void pop() {
    size_t n = q_.size();
    if (n) {
      for (size_t i = 0; i < n - 1; ++i) {
        int last_num = q_.front();
        q_.pop();
        q_.push(last_num);
      }
      q_.pop();
    }
  }

  // Get the top element.
  int top() {
    size_t n = q_.size();
    int last_num;
    for (size_t i = 0; i < n; ++i) {
      last_num = q_.front();
      q_.pop();
      q_.push(last_num);
    }
    return last_num;
  }

  // Return whether the stack is empty.
  bool empty() {
    return q_.empty();
  }
  
 private:
    
  std::queue<int> q_;

};
