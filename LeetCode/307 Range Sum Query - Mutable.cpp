class NumArray {
 
 public:
  
  NumArray(std::vector<int> &nums) {
    const int N = nums.size();
    N_ = 1;
    while (N_ < N) {
      sums_.push_back(std::vector<int>(N_, 0));
      N_ <<= 1;
    }
    sums_.push_back(std::vector<int>(N_, 0));
    D_ = sums_.size();
    for (int i = 0; i < N; ++i) {
      sums_[D_ - 1][i] = nums[i];
    }
    for (int depth = D_ - 2; depth >= 0; --depth) {
      const int M = sums_[depth].size();
      for (int i = 0; i < M; ++i) {
        sums_[depth][i] = sums_[depth + 1][i * 2] + sums_[depth + 1][i * 2 + 1];
      }
    }
  }

  void update(int i, int value) {
    sums_[D_ - 1][i] = value;
    for (int depth = D_ - 2; depth >= 0; --depth) {
      i /= 2;
      sums_[depth][i] = sums_[depth + 1][i * 2] + sums_[depth + 1][i * 2 + 1];
    }
  }

  int sumRange(int i, int j) {
    return Sum(j, 0, N_, 0, 0) - Sum(i, 0, N_, 0, 0) + sums_[D_ - 1][i];
  }

 private:

  int Sum(int k, int l, int r, int depth, int index) {
    if (k + 1 == r) {
      return sums_[depth][index];
    }
    int mid = (l + r) / 2;
    if (k < mid) {
      return Sum(k, l, mid, depth + 1, index * 2);
    }
    return sums_[depth + 1][index * 2] + Sum(k, mid + 1, r, depth + 1, index * 2 + 1);
  }

  std::vector<std::vector<int> > sums_;
  int D_;
  int N_;

};

// BIT
class NumArray {
 
 public:
  
  NumArray(std::vector<int> &nums) : nums_(nums) {
    const int N = nums.size();
    N_ = 1;
    while (N_ < N) {
      N_ <<= 1;
    }
    nodes_ = std::vector<int>(N_ + 1, 0);
    for (int i = 0; i < N; ++i) {
      Add(i + 1, nums_[i]);
    }
  }

  void update(int i, int value) {
    Add(i + 1, value - nums_[i]);
    nums_[i] = value;
  }

  int sumRange(int i, int j) {
    return Sum(j + 1) - Sum(i);
  }

 private:

  void Add(int i, int value) {
    if (i > N_) {
      return;
    }
    nodes_[i] += value;
    Add(i + (i & -i), value);
  }

  int Sum(int n) {
    return (n > 0) ? (nodes_[n] + Sum(n - (n & -n))) : 0;
  }

  std::vector<int> nums_;
  std::vector<int> nodes_;
  int N_;

};

// Segment Tree
class NumArray {
 
 public:
  
  NumArray(std::vector<int> &nums) {
    N_ = nums.size();
    int n = 1;
    while (n < N_) {
      n <<= 1;
    }
    nodes_.resize(2 * n);
    Build(nums, 0, N_, 0);
  }

  void update(int i, int value) {
    Update(i, value, 0, N_, 0);
  }

  int sumRange(int i, int j) {
    return Sum(i, j, 0, N_, 0);
  }

 private:

  void Build(const std::vector<int> &nums, int l, int r, int node_index) {
    if (l + 1 == r) {
      nodes_[node_index] = nums[l];
      return;
    }
    if (l >= r) {
      return;
    }
    int mid = (l + r) / 2;
    Build(nums, l, mid, node_index * 2 + 1);
    Build(nums, mid, r, node_index * 2 + 2);
    nodes_[node_index] = nodes_[node_index * 2 + 1] + nodes_[node_index * 2 + 2];
  }

  void Update(int target_index, int value, int l, int r, int node_index) {
    if (l + 1 == r) {
      nodes_[node_index] = value;
      return;
    }
    int mid = (l + r) / 2;
    if (target_index < mid) {
      Update(target_index, value, l, mid, node_index * 2 + 1);
    }    
    if (target_index >= mid) {
      Update(target_index, value, mid, r, node_index * 2 + 2);
    }
    nodes_[node_index] = nodes_[node_index * 2 + 1] + nodes_[node_index * 2 + 2];
  }

  int Sum(int query_l, int query_r, int l, int r, int node_index) {
    if (query_l <= l && (r - 1) <= query_r) {
      return nodes_[node_index];
    }
    int mid = (l + r) / 2;
    int sum[2] = {};
    if (query_l < mid) {
      sum[0] = Sum(query_l, query_r, l, mid, node_index * 2 + 1);
    }
    if (query_r >= mid) {
      sum[1] = Sum(query_l, query_r, mid, r, node_index * 2 + 2);
    }
    return sum[0] + sum[1];
  }

  int N_;
  std::vector<int> nodes_;

};
