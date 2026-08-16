class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        graph = [ [] for i in range(len(wordList) + 2)]
        lookUp = {}

        def constructG(word,idx,wordIdx):
            if idx == len(word):
                return 
            orig_chr = word[idx]

            for i in range(0,26):  
                if (ord(orig_chr) - ord("a")) == i:
                    continue
                word[idx] = chr(ord('a') + i) 
                chw = "".join(word)
                if chw in lookUp:
                    graph[wordIdx].append(lookUp[chw])
            word[idx] = orig_chr
            constructG(word,idx+1,wordIdx)
            return
        
        lookUp[beginWord] = 0
        for i in range(1,len(wordList)+1):
            lookUp[wordList[i-1]] = i
            print(lookUp)
        print(lookUp)
        if endWord not in lookUp:
            return 0
        

        constructG(list(beginWord),0,0)
        # constructG(list(endWord),0,len(wordList)+1)
        for i in range(1,len(wordList)+1):
            constructG(list(wordList[i-1]),0,i)

        print(graph)
        q = deque()
        q.append([0,0])
        vis = [0]*(len(wordList)+2)
        while len(q):

            node = q.popleft()
            if node[0]==lookUp[endWord]:
                return node[1]+1

            for n in graph[node[0]]:
                if vis[n]==0:
                    vis[n] = 1
                    q.append([n,node[1]+1])
        return 0
                
                

        
        
        

            


        