
class Node:
    def __init__(self):
        self.options = [None]*26
        self.count = 0
        self.isEnd = False
        self.curr = ""    

class PrefixTree:

    def __init__(self):
        self.head = Node()
        

    def insert(self, word: str) -> None:
        temp = self.head
        curr = ""
        for w in word:
            nv = ord(w)-ord("a")
            curr = curr+w
            if temp.options[nv]==None:
                node = Node()
                node.count+=1
                node.curr = curr
                temp.options[nv] = node
                temp = node
            else:
                temp = temp.options[nv]
                temp.count+=1
        
        temp.isEnd = True
        return


    def search(self, word: str) -> bool:
        temp = self.head
        for w in word:
            nv = ord(w)-ord("a")
            if temp.options[nv]==None:
                return False
            temp = temp.options[nv]   
        return temp.isEnd
        
            
        

    def startsWith(self, word: str) -> bool:

        temp = self.head
        for w in word:
            nv = ord(w)-ord("a")
            if temp.options[nv]==None:
                return False
            temp = temp.options[nv]
        
        return True


class Solution:
    
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:

        PT = PrefixTree()
        for w in words:
            PT.insert(w)

        ans = []
        vis = [[0]*len(board[0]) for i in range(len(board))]

        def dfs(i,j,node):
            if node.isEnd:
                node.isEnd = False
                ans.append(node.curr)
            if i<0 or j<0 or i>=len(board) or j>=len(board[0]) or vis[i][j]==1:
                return
            

            chn = ord(board[i][j]) - ord("a")
            nnode = node.options[chn]
            if nnode == None:
                return
            vis[i][j] = 1
            dfs(i+1,j,nnode)
            dfs(i-1,j,nnode)
            dfs(i,j+1,nnode)
            dfs(i,j-1,nnode)
            vis[i][j] = 0
            return


        for i in range(len(board)):
            for j in range(len(board[0])):
                dfs(i,j,PT.head) 
                if len(ans) == len(words):
                    break
        return ans

                     