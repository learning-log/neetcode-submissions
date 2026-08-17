import heapq
class Solution:
    def parent(self,arr,a):
        if a==arr[a]:
            return a
        pa = self.parent(arr,arr[a])
        arr[a] = pa
        return pa
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        q = []
        for i in range(len(points)):
            for j in range(i+1,len(points)):
                dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1])
                heapq.heappush(q,[dist,i,j])
        

        arr = [i for i in range(len(points))]
        ans = 0
        while len(q):
            point = heapq.heappop(q)
            # print(point)
            pa = self.parent(arr,point[1])

            pb = self.parent(arr,point[2])
            if pa != pb:
                ans = ans + point[0]
                arr[pa] = pb
            
        return ans
                
