class Solution:
    # @param {string} s
    # @return {integer}
    def titleToNumber(self, s):
        sum = 0
        for c in s:
            sum = sum * 26 + ord(c) - ord('A') + 1
        return sum
