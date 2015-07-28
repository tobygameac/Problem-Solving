class Solution:
    # @param {integer} n
    # @return {integer}
    def trailingZeroes(self, n):
        power_of_five = 5
        zero_count = 0
        while n >= power_of_five:
            zero_count += n / power_of_five
            power_of_five = power_of_five * 5
        return zero_count
