class Solution:
    def trap(self, height: List[int]) -> int:
        
        ## We are saving using the internal loops to get the left max and the right max it is time consuming so we can replace that process thorugh usage of variation of prefix and suffix arrays
        total_water:int=0
        prefix_max: List[int] =[0]*len(height)
        # print(f"{prefix_max}")
        suffix_max: List[int] = [0]*len(height)
        prefix_max[0]=height[0]
        suffix_max[len(height)-1]=height[len(height)-1]
        
        for i in range(len(height)-2,-1,-1):
            suffix_max[i]= max(height[i],suffix_max[i+1])
              
        for j in range(1,len(height)):
            prefix_max[j]=max(height[j],prefix_max[j-1])
        # print(f"{suffix_max}")
        # print(f"{prefix_max}")
        # water at specific pos
        for k in range(0,len(height)):
            total_water+= (min(prefix_max[k],suffix_max[k])- height[k])
            # print(f"{total_water}")
        return total_water