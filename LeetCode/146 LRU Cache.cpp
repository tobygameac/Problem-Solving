class LRUCache {

 public:
  
  LRUCache(int capacity) : capacity_(capacity) {
  }
    
  int get(int key) {
    if (values_.find(key) == values_.end()) {
      return -1;
    }

    keys_.erase(keys_iterator_[key]);

    keys_.push_front(key);

    keys_iterator_[key] = keys_.begin();

    return values_[key];
  }
    
  void set(int key, int value) {

    auto old_pair = keys_iterator_.find(key);
    if (old_pair != keys_iterator_.end()) {
      keys_.erase(old_pair->second);
    }
    
    keys_.push_front(key);

    if (keys_.size() > capacity_) {
      values_.erase(keys_.back());
      keys_iterator_.erase(keys_.back());
      keys_.pop_back();
    }

    keys_iterator_[key] = keys_.begin();
    values_[key] = value;        
  }

 private:
  
  std::list<int> keys_;

  std::unordered_map<int, std::list<int>::iterator> keys_iterator_;
  std::unordered_map<int, int> values_;

  int capacity_;

};
