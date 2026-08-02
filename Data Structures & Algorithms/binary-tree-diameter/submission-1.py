# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        ans = 0
        def D(root):
            nonlocal ans
            if root==None:
                return 0
            
            left = D(root.left)
            right = D(root.right)

            ans = max(ans,right+left)
            return max(right,left)+1
        D(root)
        return ans

        