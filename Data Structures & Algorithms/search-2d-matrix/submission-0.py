class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        """
            If I were to write the linear search/ complete search for this we would use 2 loops to iterate over each element in 2d integer array which would ideally take O(mxn) time and O(1) space 

            To reduce the time complexity a bit we can use binary search on rows first to find the row in which the element can exist and then perform binary search on that specific row at which that element is most probable to exist


        """
        rows: int = len(matrix) #3
        # print(rows)
        cols: int = len(matrix[0]) #4
        # print(cols)
        high_row: int = rows-1 # 2
        low_row: int = 0 
        mid_row: int =0
        while low_row<=high_row: # 0<=2
            mid_row:int = low_row + (high_row-low_row)//2 #1 
            if matrix[mid_row][0]==target:
                return True
            elif matrix[mid_row][0]<target:
                low_row=mid_row+1
            elif matrix[mid_row][0]>target:
                high_row=mid_row-1
            else: 
                break
            low:int =0
            high:int = cols-1
            while low<=high:
                mid:int= low + (high - low )//2
                if matrix[mid_row][mid]==target:
                    return True
                elif matrix[mid_row][mid]<target:
                    low=mid+1
                else:
                    high=mid-1
        return False
                    
            
                
             
