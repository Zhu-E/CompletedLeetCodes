class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """
        maxCandies=0
        n = len(candies)
        for i in range(n):
            maxCandies=max(maxCandies, candies[i])
        ans = []
        for i in range(n):
            if candies[i]+extraCandies<maxCandies:
                ans = ans + [False]
            else:
                ans = ans + [True]
        return ans
        
