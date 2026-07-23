# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head==None or head.next==None:
            return head
        curr = head
        nextt = head.next
        n_head = self.reverseList(head.next)
        nextt.next = head
        head.next = None
        return n_head