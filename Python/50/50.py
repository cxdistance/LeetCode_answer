class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        flag = 1
        result = 1
        if n < 0:
            flag = 0
            n = -n
        while n > 0:
            if n % 2 == 0:
                x = x*x
                n = n//2
            else:
                n = n-1
                result = x*result
                n = n//2
                x = x*x
        if flag == 1:
            return result
        else:
            return 1/result



