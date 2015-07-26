# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        if head == None:
            return None
        previous = head
        current = head.next
        previous.next = None
        while current != None:
            next = current.next
            current.next = previous
            previous = current
            current = next
        return previous
