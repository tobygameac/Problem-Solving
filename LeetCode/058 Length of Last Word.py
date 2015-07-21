class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLastWord(self, s):
        length = 0
        meet_char = False
        for c in s[::-1]:
            if c != ' ':
                meet_char = True
                length = length + 1
            elif meet_char != False:
                break
        return length
