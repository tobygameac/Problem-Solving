#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, vector<int> > index;
    for (int i = 0; i < nums.size(); ++i) {
      index[nums[i]].push_back(i + 1);
    }
    sort(nums.begin(), nums.end());
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
      map<int, vector<int> >::iterator it = index.find(target - nums[i]);
      if (it != index.end()) {
        if (2 * nums[i] == target) {
          ans.push_back(it->second[0]);
          ans.push_back(it->second[1]);
        } else {
          ans.push_back(index[nums[i]][0]);
          ans.push_back(it->second[0]);
        }
        sort(ans.begin(), ans.end());
        break;
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
