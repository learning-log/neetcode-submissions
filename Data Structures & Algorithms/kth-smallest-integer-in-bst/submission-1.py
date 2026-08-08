# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        
        ans = 0
        def req(root,k):
            nonlocal ans
            if root==None:
                return
            
            req(root.left,k)

            if k[0]==1:
                ans = root.val
            k[0]-=1
            req(root.right,k)
            return
        
        req(root,[k])
        return ans

