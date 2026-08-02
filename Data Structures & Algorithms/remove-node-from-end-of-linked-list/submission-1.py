# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy= ListNode(0)
        temp = head
        nc = 0
        while nc<n:
            temp = temp.next
            nc+=1
        ttemp = dummy
        ttemp.next = head

        while temp!=None:
            ttemp = ttemp.next
            temp = temp.next
        
        ttemp.next = ttemp.next.next
        return dummy.next
