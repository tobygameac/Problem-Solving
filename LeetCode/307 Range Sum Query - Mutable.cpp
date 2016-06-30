class NumArray {
 
 public:
  
  NumArray(std::vector<int> &nums) {
    const size_t N = nums.size();
    size_t n = 1;
    while (n < N) {
      n <<= 1;
    }
    while (n) {
      sums_.push_back(std::vector<int>(n, 0));
      if (n == 1) {
        break;
      }
      n >>= 1;
    }
    for (size_t i = 0; i < N; ++i) {
      update(i, nums[i]);
    }
  }

  void update(int i, int val) {
    sums_[0][i] = val;
    const size_t D = sums_.size();
    for (size_t depth = 1; depth < D; ++depth) {
      i /= 2;
      sums_[depth][i] = sums_[depth - 1][i * 2] + sums_[depth - 1][i * 2 + 1];
    }
  }

  int sumRange(int i, int j) {
    return Sum(j) - Sum(i) + sums_[0][i];
  }

 private:

  int Sum(int k) {
    int depth = sums_.size() - 1, index = 0;
    int sum = 0;
    int l = 0, r = sums_[0].size() - 1;
    while (true) {
      if (r == k) {
        sum += sums_[depth][index];
        break;
      }
      size_t mid = (l + r) / 2;
      if (k <= mid) {
        r = mid;
        depth = depth - 1;
        index = index * 2;
      } else {
        sum += sums_[depth - 1][index * 2];
        l = mid + 1;
        depth = depth - 1;
        index = index * 2 + 1;
      }
    }
    return sum;
  }

  std::vector<std::vector<int> > sums_;

};
