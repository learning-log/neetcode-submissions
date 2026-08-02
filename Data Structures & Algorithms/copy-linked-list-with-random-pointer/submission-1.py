"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        dictt = {}
        dummy = Node(1,None)

        temp = head
        tail = dummy
        while temp:
            tail.next = Node(temp.val,None)
            tail = tail.next
            
            
            dictt[temp] = tail
            temp = temp.next
        
        temp = head
        tail = dummy.next
        while temp:
            if temp.random!=None:
                rand = dictt[temp.random]
                tail.random = rand
            tail = tail.next
            temp = temp.next
        return dummy.next