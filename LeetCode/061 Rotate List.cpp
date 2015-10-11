#include <cstdio>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *rotateRight(ListNode *head, int k) {
    int length = 0;
    ListNode *current_node = head;
    while (current_node) {
      ++length;
      current_node = current_node->next;
    }
    if (!length) {
      return head;
    }
    k = (k % length);
    if (!k) {
      return head;
    }
    int index = 1;
    current_node = head;
    while (current_node) {
      if (index == length - k) {
        ListNode *tail_node = current_node;
        current_node = current_node->next;
        tail_node->next = NULL;
        ListNode *new_head = current_node;
        while (current_node->next) {
          current_node = current_node->next;
        }
        current_node->next = head;
        return new_head;
      }
      current_node = current_node->next;
      ++index;
    }
  }
};

int main() {
  return 0;
}
