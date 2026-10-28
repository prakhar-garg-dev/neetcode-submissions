class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l:int = 0 
        n:int = len(nums)
        r:int = n-1
        while l<=r :
            mid:int = (r+l)//2 # floor division to get quotient without reminders
            if (nums[mid]<target):
                l=mid+1
            elif (nums[mid]>target):
                r=mid-1
            else:
                return mid
        return -1