# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def deleteDuplicates(self, head):
        list_head = ListNode(0)
        list_head.next = head
        previous_node = list_head
        while head != None and head.next != None:
            if head.val == head.next.val:
                while head.next != None and head.val == head.next.val:
                    head.next = head.next.next
                previous_node.next = head.next
                head = previous_node
            else:
                previous_node = head
                head = head.next
        return list_head.next
