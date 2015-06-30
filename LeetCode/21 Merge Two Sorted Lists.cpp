#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  bool isDecreasing(ListNode* l) {
    while (l) {
      if (l->next && (l->next->val < l->val)) {
        return 1;
      }
      l = l->next;
    }
    return 0;
  }

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    bool decreasing = isDecreasing(l1) || isDecreasing(l2);
    ListNode* mergedList = new ListNode(-1);
    ListNode* ans = mergedList;
    while (l1 || l2) {
      bool removeFrom1 = 0;
      if (l1 && l2) {
        if (decreasing) {
          removeFrom1 = l1->val > l2->val;
        } else {
          removeFrom1 = l1->val < l2->val;
        }
      } else if (l1) {
        removeFrom1 = 1;
      }
      if (removeFrom1) {
        mergedList->next = new ListNode(l1->val);
        l1 = l1->next;
        mergedList = mergedList->next;
      } else {
        mergedList->next = new ListNode(l2->val);
        l2 = l2->next;
        mergedList = mergedList->next;
      }
    }
    ans = ans->next;
    return ans;
  }
};

int main() {
  return 0;
}
