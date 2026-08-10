class Node:
    def __init__(self):
        self.options = [None]*26
        self.isEnd = False
    

class PrefixTree:

    def __init__(self):
        self.head = Node()
        

    def insert(self, word: str) -> None:
        temp = self.head
        for w in word:
            nv = ord(w)-ord("a")
            if temp.options[nv]==None:
                node = Node()
                temp.options[nv] = node
                temp = node
            else:
                temp = temp.options[nv]
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

        
        