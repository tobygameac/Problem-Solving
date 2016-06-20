class Solution {
 
 public:
  
  ListNode *partition(ListNode *head, int x) {
    ListNode *a_head = new ListNode(-1);
    ListNode *b_head = new ListNode(-1);

    ListNode *a = a_head;
    ListNode *b = b_head;

    ListNode *node = head;

    while (node) {
      ListNode *next_node = node->next;
      if (node->val < x) {
        a->next = node;
        a = a->next;
        a->next = 0;
      } else {
        b->next = node;
        b = b->next;
        b->next = 0;
      }
      node = next_node;
    }

    a->next = b_head->next;

    return a_head->next;
  }

};
