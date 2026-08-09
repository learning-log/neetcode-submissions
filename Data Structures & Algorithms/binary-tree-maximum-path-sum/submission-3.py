# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = -10001
        def req(root):
            nonlocal ans
            if root==None:
                return 0
            
            lefttt = req(root.left)
            rightt = req(root.right)
            # ans = max(root.val,ans)

            maxxl = max(lefttt,0)
            maxxr = max(rightt,0)
            
            if ans<(maxxr+maxxl+root.val):
                ans = maxxr+maxxl+root.val



            # if ans<(lefttt+rightt+root.val):
            #     ans = (lefttt+rightt+root.val)

            rv = max(lefttt,rightt)
            rv = max(rv+root.val,root.val)
            return rv
        req(root)
        return ans
