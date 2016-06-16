class Solution {

 public:
  
  int removeDuplicates(std::vector<int> &nums) {
    const size_t N = nums.size();
    size_t new_index = 0;
    for (size_t i = 0; i < N; ++i) {
      if ((i + 2 >= N) || (nums[i] != nums[i + 2])) {
        nums[new_index++] = nums[i];
      }
    }
    return new_index;
      
  }

};
