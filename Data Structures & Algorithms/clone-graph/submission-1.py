"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        
        vis = {}
        if node==None:
            return None
        viss = {}
        def req(orgi,vis):
            if orgi.val in vis:
                return vis[orgi.val]
            
            dup = Node(orgi.val)
            vis[orgi.val] = dup
            # print(orgi.val)
            # viss[orgi.val]= 1
            for n in orgi.neighbors:
                if n.val not in vis:
                    # print(n.val)
                    new_node = req(n,vis)
                    dup.neighbors.append(new_node)
                else:
                    dup.neighbors.append(vis[n.val])
            # viss[orgi.val] = 2
            return dup
        
        ans = req(node,vis)
        print("ans",ans.val,node.val)
        return ans