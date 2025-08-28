class Solution(object):
    def prevPermOpt1(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        n = len(arr)
        postfixMin = [0 for i in range(n)]
        left=-1
        for i in range(n-1,-1,-1):
            postfixMin[i]=arr[i]
            if i!=n-1:
                postfixMin[i]=min(postfixMin[i],postfixMin[i+1])
        for i in range(n-2,-1,-1):
            if postfixMin[i+1]<arr[i]:
                left=i
                break
        if left==-1:
            return arr
        right=-1
        oldMax=0
        for i in range(n-1, left, -1):
            if arr[left]>arr[i] and arr[i]>=oldMax:
                right=i
                oldMax=arr[i]
        arr[left],arr[right]=arr[right],arr[left]
        return arr
        
