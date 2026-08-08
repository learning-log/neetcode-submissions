# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        
        q = deque()
        q.append(root)
        ans = []
        if root== None:
            return ans
        while len(q)>0:
            sz = len(q)
            # print(sz)
            ans.append(q[-1].val)
            for i in range(sz):
                node = q.popleft()
                print(node.val)
                if node.left!=None:
                    q.append(node.left)
                if node.right!=None:
                    q.append(node.right)

        return ans
            

        