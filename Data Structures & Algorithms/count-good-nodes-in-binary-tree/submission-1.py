# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:

        good = [0]

        def req(root,good,maxx):
            if root==None:
                return 
            if maxx<=root.val:
                good[0]+=1
            maxx = max(maxx,root.val)
            req(root.left,good,maxx)
            req(root.right,good,maxx)
            return
        req(root,good,-1001)
        return good[0]