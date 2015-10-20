struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    ListNode swapped_head(-1);
    swapped_head.next = head;
    ListNode *previous_node = &swapped_head;
    ListNode *current_node = head;
    while (current_node) {
      if (current_node->next) {
        previous_node->next = current_node->next;
        ListNode *next_next_node = current_node->next->next;
        current_node->next->next = current_node;
        current_node->next = next_next_node;
      } else {
        previous_node->next = current_node;
      }
      previous_node = current_node;
      current_node = current_node->next;
    }
    return swapped_head.next;
  }
};

int main() {
  return 0;
}
