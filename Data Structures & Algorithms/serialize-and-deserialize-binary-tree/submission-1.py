# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Codec:
    
    # Encodes a tree to a single string.

    def serialize(self, root: Optional[TreeNode]) -> str:
        if root==None:
            return "N"
        
        left = self.serialize(root.left)
        right = self.serialize(root.right)
        return str(root.val)+"*"+left+"*"+right


        
    # Decodes your encoded data to tree.
    def helperDe(self,data,p):
        if p[0]>=len(data):
            return None
        if data[p[0]]=="N":
            p[0]+=1
            return None
        
        node = TreeNode(data[p[0]])
        p[0] +=1
        node.left = self.helperDe(data,p)
        # print(p)
        node.right = self.helperDe(data,p)
        # print(node.val,node.left,node.right)
        return node

        
    def deserialize(self, data: str) -> Optional[TreeNode]:

        nodes = data.split("*")
        print(nodes) 

        p = [0]
        return self.helperDe(nodes,p)




