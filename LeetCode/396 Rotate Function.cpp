class Solution {
 
 public:
   
  int maxRotateFunction(std::vector<int> &A) {
    const int N = A.size();
    int sum = 0, f_sum = 0;
    for (int i = 0; i < N; ++i) {
      f_sum += i * A[i];
      sum += A[i];
    }
    int max_sum = f_sum;
    for (int i = 0; i < N; ++i) {
      f_sum = (f_sum - sum) + N * A[i];
      max_sum = std::max(max_sum, f_sum);
    }
    return max_sum;
  }

};
