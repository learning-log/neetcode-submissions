# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        ans = True
        def checkSame(p,q):
            if p==None and q==None:
                return True
            elif p==None or q==None:
                return False

            if p.val!=q.val:
                return False
            l = checkSame(p.left,q.left)

            r = checkSame(p.right,q.right)
            
            if l and r:
                return True
            return False
        
        ans  = checkSame(p,q)
        return ans
