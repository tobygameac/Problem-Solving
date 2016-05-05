class Queue {
 
 public:
  
  // Push element x to the back of queue.
  void push(int x) {
    std::stack<int> s;
    while (q_.size()) {
      s.push(q_.top());
      q_.pop();
    }
    s.push(x);
    while (s.size()) {
      q_.push(s.top());
      s.pop();
    }
  }

  // Removes the element from in front of queue.
  void pop(void) {
    q_.pop();
  }

  // Get the front element.
  int peek(void) {
    return q_.top();
  }

  // Return whether the queue is empty.
  bool empty(void) {
    return q_.empty();
  }

 private:

  std::stack<int> q_;

};
