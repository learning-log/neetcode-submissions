import copy
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        shortestFlights = [10000 for i in range(n)]
        shortestFlights[src] = 0
        lastRoundShortesF = copy.deepcopy(shortestFlights)
        for i in range(k+1):
            for flight in flights:
                if shortestFlights[flight[1]]>lastRoundShortesF[flight[0]]+flight[2]:
                    shortestFlights[flight[1]]= lastRoundShortesF[flight[0]]+flight[2]

            lastRoundShortesF = copy.deepcopy(shortestFlights)
            # print(lastRoundShor)

        return -1 if shortestFlights[dst]==10000 else shortestFlights[dst]