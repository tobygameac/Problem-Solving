class Solution {
 
 public:
  
  std::vector<std::vector<int> > permute(std::vector<int> &nums) {
    std::vector<std::vector<int> > permutations;
    std::sort(nums.begin(), nums.end());
    do {
      permutations.push_back(nums);
    } while (std::next_permutation(nums.begin(), nums.end()));
    return permutations;
  }

};
