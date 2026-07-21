# class Solution:    
#     def minWindow(self, s: str, t: str) -> str:
#         # def checkInclusion(self, s1: str, s2: str) -> bool:
#         tdictt = {}
#         start = 0
#         end = 0
#         ansLen = 10000
#         ansstart = 0
#         ansend = 0
#         ansF = False

#         while end<len(t):
#             tdictt[t[end]] = tdictt.get(t[end],0)+1
#             end+=1

#         end=0
#         bdictt = {}
#         lent = len(tdictt)
#         lenb = 0

#         while end<len(s):
#             curr = s[end]
#             if curr in tdictt.keys():
#                 bdictt[curr] = bdictt.get(curr,0) +1
#                 if bdictt[curr]==tdictt[curr]:
#                     lenb += 1
#             else:
#                 if start==end:
#                     start+=1
#             while start < end and (s[start] not in tdictt.keys() or bdictt[s[start]]>tdictt[s[start]]):
#                 if s[start] not in tdictt.keys():
#                     start +=1
#                 else:
#                     bdictt[s[start]]-=1 
#                     start+=1
#             if lenb==lent:
#                 ansF = True
#                 if ansLen>(end - start +1 ):
#                     ansstart = start
#                     ansend = end
#                     ansLen = end - start +1
#             end +=1
        
#         return s[ansstart:ansend+1] if ansF else ""
            
from collections import Counter

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""

        # Dictionary which keeps a count of all the unique characters in t.
        dict_t = Counter(t)
        required = len(dict_t)

        # Left and Right pointer
        l, r = 0, 0

        # formed is used to track how many unique characters in t 
        # are present in the current window in their desired frequency.
        formed = 0
        window_counts = {}

        # ans tuple of the form (window length, left, right)
        ans = float("inf"), None, None

        while r < len(s):
            char = s[r]
            # Only track characters that are actually in T
            if char in dict_t:
                window_counts[char] = window_counts.get(char, 0) + 1
                if window_counts[char] == dict_t[char]:
                    formed += 1

            # Try and contract the window till the point where it ceases to be 'valid'.
            while l <= r and formed == required:
                char = s[l]

                # Update the smallest window
                if r - l + 1 < ans[0]:
                    ans = (r - l + 1, l, r)

                # The character at the position pointed by the `left` pointer is no longer a part of the window.
                if char in dict_t:
                    window_counts[char] -= 1
                    if window_counts[char] < dict_t[char]:
                        formed -= 1
                
                l += 1    

            r += 1    
            
        return "" if ans[0] == float("inf") else s[ans[1] : ans[2] + 1]
        

        