#include <cstdio>

class MinStack {
 public:
  MinStack() : top_node(NULL), min_top_node(NULL) {}

  void push(int x) {
    if (top_node) {
      Node *previous_top_node = top_node;
      top_node = new Node(x);
      top_node->next = previous_top_node;
    } else {
      top_node = new Node(x);
    }

    if (min_top_node) {
      if (x <= getMin()) {
        Node *previous_min_top_node = min_top_node;
        min_top_node = new Node(x);
        min_top_node->next = previous_min_top_node;
      }
    } else {
      min_top_node = new Node(x);
    }
  }

  void pop() {
    if (top_node) {
      if (min_top_node) {
        if (top_node->value <= min_top_node->value) {
          Node *previous_min_top_node = min_top_node;
          min_top_node = min_top_node->next;
          delete previous_min_top_node;
        }
      }
      Node *previous_top_node = top_node;
      top_node = top_node->next;
      delete previous_top_node;
    }
  }

  int top() {
    return top_node ? top_node->value : 0;
  }

  int getMin() {
    return min_top_node ? min_top_node->value : 0;
  }

  struct Node {
    Node(int value) : value(value), next(NULL) {}
    int value;
    Node *next;
  };

  Node *top_node;
  Node *min_top_node;
};

int main() {
  return 0;
}
