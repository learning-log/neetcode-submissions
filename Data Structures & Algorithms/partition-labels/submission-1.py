class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        
        dictt = {}
        for i in range(len(s)):
            if s[i] in dictt:
                dictt[s[i]][1] = i
            else:
                dictt[s[i]] = [i,i]
        print(dictt)
        ans = []
        maxx = -1
        curr = 0
        for i in range(len(s)):
            maxx = max(maxx,dictt[s[i]][1])
            curr = curr + 1
            if i == maxx:
                ans.append(curr)
                curr = 0
  
        return ans