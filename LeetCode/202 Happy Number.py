class Solution:
    # @param {integer} n
    # @return {boolean}
    def isHappy(self, n):
        rec = set()
        return self.happy(n, rec)

    def happy(self, n, rec):
        sum = 0
        for c in str(n):
            sum += (ord(c) - ord('0')) ** 2
        if sum in rec:
            return False
        rec.add(sum)
        if sum == 1:
            return True
        return self.happy(sum, rec)
