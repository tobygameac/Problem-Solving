class Solution:
    # @return {integer}
    def climbStairs(self, n):
        if n <= 1:
            return 1
        a = 1
        b = 1
        c = 0
        for stair in range(2, n + 1):
            c = a + b
            a = b
            b = c
        return c
