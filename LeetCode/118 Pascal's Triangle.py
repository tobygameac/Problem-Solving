class Solution:
    # @param {integer} numRows
    # @return {integer[][]}
    def generate(self, numRows):
        pascal_triangle = []
        for r in range(numRows):
            pascal_triangle_row = [1]
            for c in range(1, r + 1):
                value = pascal_triangle[r - 1][c - 1]
                if c < r:
                    value = value + pascal_triangle[r - 1][c]
                pascal_triangle_row.append(value)
            pascal_triangle.append(pascal_triangle_row)
        return pascal_triangle
