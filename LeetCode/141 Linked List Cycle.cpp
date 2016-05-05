class Solution {
 
 public:
   
  bool hasCycle(ListNode *head) {
    ListNode *current = head;
    while (current) {
      ListNode *prev = current;
      current = current->next;
      if (current && current == head) {
        return true;
      }
      prev->next = head;
    }
    return false;
  }
};
