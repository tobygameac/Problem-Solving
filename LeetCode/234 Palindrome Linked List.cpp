class Solution {
 
 public:
   
  bool SameList(ListNode *l1, ListNode *l2) {
    while (l1 && l2) {
      if (l1->val != l2->val) {
        return false;
      }
      l1 = l1->next;
      l2 = l2->next;
    }
    return !l1 && !l2;
  }

  void ReverseList(ListNode *head) {
    ListNode *previous = NULL;
    ListNode *current = head;
    while (current) {
      ListNode *next = current->next;
      current->next = previous;
      previous = current;
      current = next;
    }
    head = previous;
  }

  bool isPalindrome(ListNode *head) {
    size_t length = 0;
    ListNode *node = head;
    while (node) {
      ++length;
      node = node->next;
    }
    size_t mid = length / 2;
    ListNode *l2 = head;
    size_t i = 0;
    while (l2) {
      if (i >= mid + (length & 1)) {
        break;
      }
      ListNode *next = l2->next;
      if (i == mid - 1) {
        l2->next = NULL;
      }
      l2 = next;
      ++i;
    }
    ListNode *l1 = ReverseList(head);
    return SameList(head, l2);
  }
};
