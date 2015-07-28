class Solution:
    # @param {integer} rowIndex
    # @return {integer[]}
    def getRow(self, rowIndex):
        pascal_triangle_row = [1]
        for r in range(rowIndex):
            for c in range(r + 1, 0, -1):
                value = pascal_triangle_row[c - 1]
                if c <= r:
                    value = value + pascal_triangle_row[c]
                    pascal_triangle_row[c] = value
                else:
                    pascal_triangle_row.append(value)
        return pascal_triangle_row
