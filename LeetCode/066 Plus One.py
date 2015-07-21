class Solution:
    # @param {integer[]} digits
    # @return {integer[]}
    def plusOne(self, digits):
        carry = 1
        for i in range(len(digits) - 1, -1, -1):
            digits[i] = digits[i] + carry
            carry = digits[i] / 10
            digits[i] = digits[i] % 10
        if carry > 0:
            digits.insert(0, carry)
        return digits
