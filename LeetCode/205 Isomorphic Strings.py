class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isIsomorphic(self, s, t):
        mapping = [0 for i in range(256)]
        r_mapping = [0 for i in range(256)]
        for i in range(0, len(s)):
            mapping_c = mapping[ord(s[i])]
            if mapping_c:
                if mapping_c != t[i]:
                    return False
            else:
                if r_mapping[ord(t[i])]:
                    return False
                mapping[ord(s[i])] = t[i];
                r_mapping[ord(t[i])] = s[i];
                
        return True
