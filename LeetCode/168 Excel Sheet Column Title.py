class Solution:
    # @param {integer} n
    # @return {string}
    def convertToTitle(self, n):
        title = ''
        while n:
            n = n - 1
            title += chr(ord('A') + (n % 26))
            n = n / 26
        return title[::-1]
