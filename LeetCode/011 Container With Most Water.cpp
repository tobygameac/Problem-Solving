class Solution {
 
 public:
  
  int maxArea(std::vector<int> &height) {
    const int N = height.size();
    int max_area = 0;
    int max_left = 0;
    for (int i = 0; i < N; ++i) {
      if (height[i] <= max_left) {
        continue;
      }
      max_left = height[i];
      for (int j = N - 1; j > i; --j) {
        int area = std::min(height[i], height[j]) * (j - i);
        max_area = std::max(area, max_area);
        if (height[i] * (j - i) <= max_area) {
          break;
        }
      }
    }
    return max_area;
  }

};

class Solution {
 
 public:
  
  int maxArea(std::vector<int> &height) {
    const int N = height.size();
    int max_area = 0;
    for (int l = 0, r = N - 1; l < r;) {
      max_area = std::max(max_area, std::min(height[l], height[r]) * (r - l));
      if (height[l] < height[r]) {
        ++l;
      } else {
        --r;
      }
    }
    return max_area;
  }

};
