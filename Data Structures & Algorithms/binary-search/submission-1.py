class Solution:
    def recurse(self,l:int , r:int ,target:int, nums:List[int] )->int :
        mid: int = l + (r-l)//2 
        if l>r:
            return -1
        if nums[mid]==target:
            return mid
        if nums[mid]> target:
            return self.recurse(l,mid-1,target,nums)
        else:
            return self.recurse(mid+1,r,target,nums)
        
    def search(self, nums: List[int], target: int) -> int:
        # Recursive approach
        n:int = len(nums)
        l:int = 0
        r:int = n-1
        return self.recurse(l,r,target,nums)