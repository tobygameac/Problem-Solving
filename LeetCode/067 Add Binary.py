class Solution:
    # @param {string} a
    # @param {string} b
    # @return {string}
    def addBinary(self, a, b):
        l1 = len(a) - 1
        l2 = len(b) - 1
        c = ""
        carry = 0
        while l1 >= 0 or l2 >= 0:
          num = carry
          if l1 >= 0 and a[l1] == '1':
              num = num + 1
          if l2 >= 0 and b[l2] == '1':
              num = num + 1
          carry = num / 2
          num = num % 2
          c += str(num)
          l1 = l1 - 1
          l2 = l2 - 1
        if carry > 0:
            c += '1'
        return c[::-1]
