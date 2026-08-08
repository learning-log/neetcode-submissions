# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        def req(root,minn,maxx):
            if root==None:
                return [True]
            
            if root.val<maxx and root.val>minn:
                

                left = req(root.left, minn, root.val)
                right = req(root.right, root.val, maxx)
            
                if left[0] and right[0]:
                    return [True]
                else:
                    return [False]


            else:
                return [False]

        return req(root,-1000000000,1000000000)[0]
        