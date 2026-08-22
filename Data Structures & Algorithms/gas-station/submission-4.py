class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        
        rangee = 0
        start = 0
        for i in range(len(gas)):
            if rangee<0:
                start = i
                rangee = 0
            rangee = gas[i]+rangee -cost[i]

        
            
        # print(start)
        for i in range(len(gas)):
            if rangee < 0:
                return -1
            if start == i:
                break
            # print(rangee,gas[i],cost[i])
            rangee = gas[i]+rangee - cost[i]
            # print(rangee)
            
            
        return start
