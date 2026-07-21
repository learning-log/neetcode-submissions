class Solution:
    def check(self,dictt,dictt2):
        for k, v in dictt.items():
            v2 = dictt2.get(k,0)
            if v!=v2:
                return False
        return True
    def checkInclusion(self, s1: str, s2: str) -> bool:
        dictt = {}
        start = 0
        end = 0

        while end<len(s1):
            dictt[s1[end]] = dictt.get(s1[end],0)+1
            end+=1
        end = 0

        dictt2 = {}
        while end<len(s2):
            fq = dictt2.get(s2[end],0)
            if s2[end] in dictt and fq<dictt[s2[end]]:
                dictt2[s2[end]] = 1+fq
            elif s2[end] not in dictt:
                while start < end:
                    dictt2[s2[start]]-=1
                    start +=1
                start+=1
            else:
                while dictt2[s2[end]]>=dictt[s2[end]]:
                    dictt2[s2[start]]-=1
                    start +=1
                dictt2[s2[end]] += 1
            if self.check(dictt,dictt2):
                return True
            end+=1




        return False

        