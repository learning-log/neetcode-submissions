class Solution:
    def mergeTriplets(self, triplets: List[List[int]], target: List[int]) -> bool:
        curr = [-1,-1,-1]

        for v in triplets:
            if v[0]<=target[0] and v[1]<=target[1] and v[2]<=target[2]:
                curr[0] = max(curr[0],v[0])
                curr[1] = max(curr[1],v[1])
                curr[2] = max(curr[2],v[2])
            
            if curr[0] == target[0] and curr[1] == target[1] and curr[2] == target[2]:
                return True
        return False
