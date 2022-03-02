# Binary Search
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        left=0
        right=len(nums)-1
        
        while left<right:
          mid=(left+right)//2
          if nums[mid]<nums[mid+1]:
            left=mid+1
          else:
            right=mid
        return left
          
# Linear Search
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        peak=0
        max=nums[0]
        for idx in range(1, len(nums)):
          print(max)
          if max<nums[idx]:
            max=nums[idx]
            peak=idx
            
        return peak