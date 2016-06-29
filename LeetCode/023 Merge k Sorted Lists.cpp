class Solution {

 public:
    
  ListNode *mergeKLists(std::vector<ListNode *> &lists) {
    ListNode temp_head(-1);
    ListNode *new_list = &temp_head;
    std::priority_queue<std::pair<int, int> > first_k_nodes;
    std::vector<ListNode *> current_nodes = lists;
    const size_t N = current_nodes.size();
    for (size_t i = 0; i < N; ++i) {
      if (current_nodes[i]) {
        first_k_nodes.push(std::make_pair(-current_nodes[i]->val, i));
      }
    }
    while (!first_k_nodes.empty()) {
      int target_index = first_k_nodes.top().second;
      first_k_nodes.pop();
      new_list->next = current_nodes[target_index];
      current_nodes[target_index] = current_nodes[target_index]->next;
      if (current_nodes[target_index]) {
        first_k_nodes.push(std::make_pair(-current_nodes[target_index]->val, target_index));
      }
      new_list = new_list->next;
    }
    new_list->next = 0;
    return temp_head.next;
  }

};
