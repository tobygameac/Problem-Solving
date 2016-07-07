class Solution {
 
 public:
  
  int hIndex(std::vector<int> &citations) {
    const size_t N = citations.size();
    int min_citation = N;
    int h = 0;
    int l = 0, r = N;
    while (l < r) {
      int mid = (l + r) / 2;
      if (citations[mid] >= (N - mid)) {
        h = N - mid;
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return h;
  }

};

