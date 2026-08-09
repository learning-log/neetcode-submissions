# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:

        def req(preorder,inorder,st,end,p)->Optional[TreeNode]:
            nonlocal dictt
            if st>end:
                return None
            if p[0]>=len(preorder):
                return None
            
            val = preorder[p[0]]
            i = dictt[val]
            
            node = TreeNode(val)
            p[0]+=1
            node.left = req(preorder,inorder,st,i-1,p)
            node.right = req(preorder,inorder,i+1,end,p)
            return node
        p = [0]
        dictt = {}
        for i in range(len(inorder)):
            dictt[inorder[i]] = i
        

        return req(preorder,inorder,0,len(preorder)-1,p)



        