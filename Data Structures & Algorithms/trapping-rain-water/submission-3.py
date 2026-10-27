class Solution:
    def trap(self, height: List[int]) -> int:
        n:int = len(height)
        l:int =0
        r:int = n-1
        maxLeft:int = height[l]
        maxRight:int = height[r]
        total:int =0
        # the shorter among the left and right decides the movement as the water can't go above the shorter of the two. 
        # So for the one which is shorter we will move the pointer forward/backward
        # The water storage is calculated by the max uptil that index - height at that index
        # updating the maxLeft before water storage calc so that right total for the index is calculated 
        while l<r:
            if maxLeft<=maxRight:
                l+=1
                maxLeft=max(height[l],maxLeft)
                total+=maxLeft-height[l]
            elif maxRight<maxLeft:
                r-=1
                maxRight=max(height[r],maxRight)
                total+=maxRight-height[r]
        return total


                