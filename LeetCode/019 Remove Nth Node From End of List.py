# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} n
    # @return {ListNode}
    def removeNthFromEnd(self, head, n):
        temp_head = ListNode(0)
        temp_head.next = head
        n_nodes_after_head = temp_head
        for i in range(n):
            n_nodes_after_head = n_nodes_after_head.next
        current_node = temp_head
        while n_nodes_after_head != None:
            if n_nodes_after_head.next == None:
                current_node.next = current_node.next.next
            n_nodes_after_head = n_nodes_after_head.next
            current_node = current_node.next
        return temp_head.next
