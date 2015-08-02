class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        result = 0
        for bit in range(0, 32):
            result = (result << 1) + (n & 1)
            n = n >> 1
        return result
