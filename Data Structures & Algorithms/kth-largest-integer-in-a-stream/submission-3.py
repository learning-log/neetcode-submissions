from queue import PriorityQueue
class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.pq = PriorityQueue()
        self.k = k

        i = 0
        while i<len(nums):
            if i<k:
                self.pq.put(nums[i])
            else:
                top = self.pq.get()
                if top<nums[i]:
                    self.pq.put(nums[i])
                else:
                    self.pq.put(top)
            i+=1
            print(i)
        
    def add(self, val: int) -> int:
        if self.k>self.pq.qsize():
            self.pq.put(val)
        else:
            top = self.pq.get()
            if top<val:
                self.pq.put(val)
            else:
                self.pq.put(top)
        top = self.pq.get()
        self.pq.put(top)
        return top
