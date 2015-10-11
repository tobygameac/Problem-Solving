#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int length_a = list_length(headA);
    int length_b = list_length(headB);

    while (length_a != length_b) {
      if (length_a > length_b) {
        headA = headA->next;
        --length_a;
      } else {
        headB = headB->next;
        --length_b;
      }
    }

    while (true) {
      if (headA == headB) {
        return headA;
      }
      headA = headA->next;
      headB = headB->next;
    }
  }
  
  int list_length(ListNode *head) {
    int length = 0;
    while (head) {
      ++length;
      head = head->next;
    }
    return length;
  }
};

int main() {
  return 0;
}
