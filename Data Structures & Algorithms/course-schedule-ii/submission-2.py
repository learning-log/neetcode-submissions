class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        graph = [[] for i in range(numCourses)]
        ans = []
        inDegree = [0] * numCourses
        for p in prerequisites:
            graph[p[1]].append(p[0])
            inDegree[p[0]]+=1
        q = deque()
        for i in range(numCourses):
            if inDegree[i]==0:
                print(i)
                q.append(i)
        while len(q)>0:
            course = q.popleft()
            ans.append(course)
            for n in graph[course]:
                inDegree[n]-=1
                if inDegree[n]==0:
                    q.append(n)

        # print(graph
        return ans if len(ans) == numCourses else []

        