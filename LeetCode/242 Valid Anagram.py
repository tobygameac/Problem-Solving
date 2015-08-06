class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        count = [0 for i in range(26)]
        for c in s:
            count[ord(c) - ord('a')] = count[ord(c) - ord('a')] + 1
        for c in t:
            count[ord(c) - ord('a')] = count[ord(c) - ord('a')] - 1
        for n in count:
            if n != 0:
                return False
        return True
