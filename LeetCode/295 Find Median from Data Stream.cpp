class MedianFinder {
 
 public:
  
  void addNum(int num) {
    if (!min_heap_.size() || (min_heap_.size() < max_heap_.size())) {
      min_heap_.push(num);
      return;
    }

    if (num < min_heap_.top()) {
      max_heap_.push(num);
      if (max_heap_.size() > min_heap_.size()) {
        min_heap_.push(max_heap_.top());
        max_heap_.pop();
      }
    } else {
      if (min_heap_.size() > max_heap_.size()) {
        max_heap_.push(min_heap_.top());
        min_heap_.pop();
      }
      min_heap_.push(num);
    }

  }

  double findMedian() {
    if (max_heap_.size() == min_heap_.size()) {
      return (max_heap_.top() + min_heap_.top()) * 0.5;
    }
    return min_heap_.top();
  }

 private:

  std::priority_queue<int> max_heap_;
  std::priority_queue<int, std::vector<int>, std::greater<int> > min_heap_;

};
