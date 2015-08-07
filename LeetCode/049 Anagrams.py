class Solution:
    # @param {string[]} strs
    # @return {string[]}
    def anagrams(self, strs):
        anagrams_count = dict()
        sorted_strs = [''.join(sorted(s)) for s in strs]
        for s in sorted_strs:
            if s in anagrams_count:
                anagrams_count[s] = anagrams_count[s] + 1
            else:
                anagrams_count[s] = 1
        ans = []
        for i in range(len(strs)):
            if anagrams_count[sorted_strs[i]] > 1:
                ans.append(strs[i])
        return ans
