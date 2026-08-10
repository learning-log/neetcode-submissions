class Node:
    def __init__(self):
        self.options = [None]*26
        self.isEnd = False
    





class WordDictionary:

    def __init__(self):
        self.head = Node()

    def addWord(self, word: str) -> None:
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
        def reqSearch(temp,word,i):
            if i == len(word):
                return temp.isEnd
            if word[i] == ".":
                for v in range(26):
                    if temp.options[v]!=None and reqSearch(temp.options[v],word,i+1):
                        return True
                return False
            else:
                nv = ord(word[i]) - ord("a")
                if temp.options[nv] == None:
                    return False
                else:
                    return reqSearch(temp.options[nv],word,i+1)
            
        return reqSearch(temp,word,0)
