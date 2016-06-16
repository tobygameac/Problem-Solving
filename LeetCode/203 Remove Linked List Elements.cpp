class Solution {

 public:
  
  ListNode *removeElements(ListNode *head, int val) {
    ListNode new_head(-1);
    new_head.next = head;
    ListNode *previous = &new_head;
    ListNode *current = head;
    while (current) {
      if (current->val == val) {
        previous->next = current->next;
      } else {
        previous = current;
      }
      current = current->next;
    }
    return new_head.next;
  }

};
