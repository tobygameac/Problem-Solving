class Solution {
 
 public:
  
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *first = head;
    ListNode *previous = head;
    ListNode *current = head;
    while (current && current->next) {
      current = current->next;
      if (current->val == previous->val) {
        previous->next = current;
      }
      previous = current;
    }
    return first;
  }

};
