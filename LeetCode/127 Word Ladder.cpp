#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {        
    vector<string> word_list;
    word_list.push_back(beginWord);
    for (auto str : wordDict) {
      word_list.push_back(str);
    }
    word_list.push_back(endWord);
    vector<vector<int> > connected_words(word_list.size());
    for (int i = 0; i < word_list.size(); ++i) {
      for (int j = i + 1; j < word_list.size(); ++j) {
        int different_char_count = 0;
        for (int char_index = 0; word_list[i][char_index] && different_char_count <= 1; ++char_index) {
          different_char_count += word_list[i][char_index] != word_list[j][char_index];
        }
        if (different_char_count == 1) {
          connected_words[i].push_back(j);
          connected_words[j].push_back(i);
        }
      }
    }

    vector<int> visited(word_list.size());
    queue<pair<int, int> > q;
    q.push(make_pair(0, 1));
    visited[0] = 1;
    while (!q.empty()) {
      pair<int, int> top = q.front();
      q.pop();
      int current_str_index = top.first;
      int current_length = top.second;
      for (auto i : connected_words[current_str_index]) {
        if (!visited[i]) {
          if (i == word_list.size() - 1) {
            return current_length + 1;
          }
          visited[i] = 1;
          q.push(make_pair(i, current_length + 1));
        }
      }
    }
    return 0;
  }
};

int main() {
  return 0;
}
