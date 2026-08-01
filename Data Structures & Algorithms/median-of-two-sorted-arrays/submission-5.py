class Solution:
            
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        Infi = 1000001
        if len(nums1)>len(nums2):
            return self.findMedianSortedArrays(nums2,nums1)

        if len(nums2)==0:
            return 0
        # if len(nums2)==0:
        #     return nums1[len(nums1)//2] if len(nums1)%2==0 else (nums1[len(nums1)//2] + nums1[len(nums1)//2 + 1]) 
        start_f = 0
        end_f = len(nums1)-1
        mid = (len(nums1)+len(nums2)+1)//2

        while True:
            mid_f = (start_f+end_f)//2
            mid_s = mid -(mid_f+1) -1
            
            print(mid_f,mid_s)
            # print(mid_s)
            
            
            aleft = nums1[mid_f] if mid_f>=0 else -Infi
            aright = nums1[mid_f+1] if (mid_f+1)<len(nums1) else Infi
            bleft = nums2[mid_s] if mid_s>=0 else -Infi
            bright = nums2[mid_s+1] if (mid_s+1)<len(nums2) else Infi
            print(aleft,aright,bleft,bright)
            if aleft<=bright and bleft<=aright:
                if (len(nums1)+len(nums2))%2==0:
                    return (max(aleft,bleft)+min(aright,bright))/2
                else:
                    return max(aleft,bleft)
            elif aleft>bright:
                end_f = mid_f-1
            else:
                
                start_f  = mid_f+1
    
        return -1
                    
                    

