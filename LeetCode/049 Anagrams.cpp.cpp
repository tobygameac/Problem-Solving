#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
 public:
  vector<string> anagrams(vector<string> &strs) {
    vector<string> sorted_strs(strs.size());
    map<string, int> anagrams_count;
    for (int i = 0; i < strs.size(); ++i) {
      sorted_strs[i] = strs[i];
      sort(sorted_strs[i].begin(), sorted_strs[i].end());
      ++anagrams_count[sorted_strs[i]];
    }
    vector<string> ans;
    for (int i = 0; i < strs.size(); ++i) {
      if (anagrams_count[sorted_strs[i]] > 1) {
        ans.push_back(strs[i]);
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
