class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        time = []
        speed_time = []
        for i in range(len(speed)):
            time.append((target-position[i])/speed[i])
        
        for i in range(len(speed)):
            speed_time.append([position[i],time[i]])
        # sorted(speed_time)
        speed_time.sort()
        print(speed_time)
        stack = []
        i = len(speed)-1
        # ans = 0
        while i>=0:
            tt = speed_time[i][1]   
            if len(stack)==0 or stack[-1]<tt:
                stack.append(tt)
            i-=1
        return len(stack)


