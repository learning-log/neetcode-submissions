class Solution:
    def swap(self,nums,i,j):
            a = nums[i]
            nums[i] = nums[j]
            nums[j] = a
            return
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []

        
        def req(i):
            if i==len(nums):
                print(i)
                ans.append(nums.copy())
                return
        
            req(i+1)
            j = i+1

            while j<len(nums):
                self.swap(nums,i,j)
                req(i+1)
                self.swap(nums,i,j)
                j+=1
            return
        req(0)
        return ans
