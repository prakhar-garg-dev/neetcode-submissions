class Solution:
    def calcPile(self,piles: list[int], number_of_bananas: int, h: int) -> bool:
            total_pile_finish_time = 0
            for pile in piles:
                single_pile_finish_time = pile // number_of_bananas
                total_pile_finish_time += single_pile_finish_time
                if pile % number_of_bananas != 0:
                    # As in one hr koko can eat number_of_bananas bananas thus it will need one more hr to eat the remaining bananas < k 
                    total_pile_finish_time += 1
                if total_pile_finish_time>h:
                    return False
            return total_pile_finish_time <= h
    def minEatingSpeed(self, piles: list[int], h: int) -> int:
        # Koko eats bananas
        # Koko has the following constraints in eating bananas
        # The guard is only away for h hrs during which Koko has to finish all bananas
        # koko have to attain a min speed k to achieve the above goal
        # meaning she has to eat k bananas/hr from each pile to completely finish all the piles before the guard returns
        # if the pile had only k bananas she will eat only k bananas in that hr

        # [1,k] , [1,k] , [1,k] , [1,k] , [1.k] ... n
        # if pile < k : eat all
        # if pile > k : eat k
        # if pile == k : eat k
        # So it is somewhat similar to binary search on answer
        # We should do one thing k should be searched in answer array which we imagine
        # from 1 to max(piles)
        

        left: int = 1
        right: int = max(piles)
        while left <= right:
            mid: int = left + (right - left) // 2
            if self.calcPile(piles,mid,h):
                right = mid -1
            else:
                left = mid + 1
        return left
