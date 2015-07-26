class Solution:
    # @param {string} s
    # @param {integer} numRows
    # @return {string}
    def convert(self, s, numRows):
        str_list = [""] * numRows
        increasing = True
        row_index = 0
        for c in s:
            str_list[row_index] += c
            if increasing:
                row_index = row_index + 1
                if row_index >= numRows:
                    row_index -= 2
                    increasing = False
            else:
                row_index = row_index - 1
                if row_index < 0:
                    row_index += 2
                    increasing = True
        ans = ""
        for s in str_list:
            ans += s
        return ans
