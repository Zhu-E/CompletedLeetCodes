class Solution(object):
    def numOfUnplacedFruits(self, fruits, baskets):
        """
        :type fruits: List[int]
        :type baskets: List[int]
        :rtype: int
        """
        occupied = [False]*len(baskets)
        n = len(fruits)
        placed = 0
        for i in range(n):
            for j in range(n):
                if not occupied[j] and fruits[i]<=baskets[j]:
                    occupied[j]=True
                    placed+=1
                    break
        return n-placed
        
        
