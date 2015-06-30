#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* result = new ListNode(-1);
    ListNode* head = result;
    int carry = 0;
    while (l1 || l2) {
      int value = carry;
      if (l1) {
        value += l1->val;
        l1 = l1->next;
      }
      if (l2) {
        value += l2->val;
        l2 = l2->next;
      }
      carry = value / 10;
      value = value % 10;
      ListNode* nextNode = new ListNode(value);
      result->next = nextNode;
      result = result->next;
    }
    if (carry) {
      ListNode* nextNode = new ListNode(carry);
      result->next = nextNode;
    }
    ListNode* ans = head->next;
    return ans;
  }
};

int main() {
  return 0;
}
