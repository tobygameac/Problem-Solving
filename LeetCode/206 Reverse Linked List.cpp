class Solution {
 public:
  ListNode *reverseList(ListNode *head) {
    ListNode *reversed_head = NULL;
    ListNode *current_node = head;
    while (current_node) {
      ListNode *temp = reversed_head;
      reversed_head = current_node;
      current_node = current_node->next;
      reversed_head->next = temp;
    }
    return reversed_head;
  }
};

int main() {
  return 0;
}
