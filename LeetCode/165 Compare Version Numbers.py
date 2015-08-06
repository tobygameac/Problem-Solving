class Solution:
    # @param {string} version1
    # @param {string} version2
    # @return {integer}
    def compareVersion(self, version1, version2):
        i = j = 0
        while i < len(version1) or j < len(version2):
            v1 = v2 = 0
            while i < len(version1):
                if version1[i] != '.':
                    v1 = v1 * 10 + ord(version1[i]) - ord('0')
                    i = i + 1
                else:
                    i = i + 1
                    break
            while j < len(version2):
                if version2[j] != '.':
                    v2 = v2 * 10 + ord(version2[j]) - ord('0')
                    j = j + 1
                else:
                    j = j + 1
                    break
            if v1 > v2:
                return 1
            if v1 < v2:
                return -1
        return 0
