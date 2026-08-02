# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverse(self,head):

        if head==None or head.next==None:
            return head
        nextt = head.next
        n_head = self.reverse(head.next)
        nextt.next = head
        head.next = None
        return n_head

    def reorderList(self, head: Optional[ListNode]) -> None:
        if head==None or head.next==None:
            return
        
        first = head
        second = head.next

        while second and second.next:
            first = first.next
            second = second.next.next
        print(first.val)
        second = first.next
        first.next = None
        
        first = head
        rev_second = self.reverse(second)
        print(first.val)
        while first!=None:
            print(first.val)
            nextt = first.next

            
            if rev_second!=None:
                print(rev_second.val,"re")
                first.next = rev_second
                rev_next = rev_second.next
                rev_second.next = nextt
                rev_second = rev_next

            first = nextt