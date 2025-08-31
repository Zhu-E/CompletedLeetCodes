class Solution:
    def maxSum(self, nums: List[int]) -> int:
        seen = set()
        ans = 0
        maximum = -9999
        for i in nums:
            if i not in seen and i>0:
                seen.add(i)
                ans += i
            maximum=max(maximum, i)
        if maximum<0:
            return maximum
        return ans


