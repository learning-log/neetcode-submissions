class Solution:
    def parent(self,arr,a):
        if a==arr[a]:
            return a
        pa = self.parent(arr,arr[a])
        arr[a] = pa
        return pa

    # def union(self,arr,a,b):
    #     pa = self.parent(arr,a)
    #     pb = self.parent(arr,b)
    #     arr[pa] = pb
    #     # if pa == pb:
    #     #     return True
    #     return False
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        arr = [i for i in range(0,len(edges)+1)]
        print(arr)
        rank = [1 for i in range(0,len(edges)+1)]

        for e in edges:
            pa = self.parent(arr,e[0])
            pb = self.parent(arr,e[1])
            if pa==pb:
                return e
            else:
                if rank[pa]>rank[pb]:
                    arr[pa] = pb
                elif rank[pa]==rank[pb]:
                    arr[pa] = pb
                    rank[pa] +=1
                else:
                    arr[pb] = pa

        return []
            
            


        