using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
   ListNode *reverseBetween(ListNode *head, int m, int n) {
     ListNode *previous_tail = NULL;
     ListNode *following_head = NULL;

     ListNode *current_node = head;

     ListNode *reversed_head = NULL;
     ListNode *reversed_tail = NULL;

     int current_index = 1;

     while (current_node) {
       if (current_index >= m && current_index <= n) {
        ListNode *reversed_temp = reversed_head;
        reversed_head = current_node;

        current_node = current_node->next;
        ++current_index;

        reversed_head->next = reversed_temp;
        
        if (!reversed_tail) {
          reversed_tail = reversed_head;
        }

        continue;
       }
       
       if (current_index == m - 1) {
         previous_tail = current_node;
       } else if (current_index == n + 1) {
         following_head = current_node;
       }
       current_node = current_node->next;
       ++current_index;
     }

     if (previous_tail) {
       previous_tail->next = reversed_head;
     } else {
       head = reversed_head;
     }

     if (following_head) {
       reversed_tail->next = following_head;
     }

     return head;
   }
};

int main() {
  return 0;
}
