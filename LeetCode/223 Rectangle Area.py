class Solution:
    # @param {integer} A
    # @param {integer} B
    # @param {integer} C
    # @param {integer} D
    # @param {integer} E
    # @param {integer} F
    # @param {integer} G
    # @param {integer} H
    # @return {integer}
    def computeArea(self, A, B, C, D, E, F, G, H):
      total_area = (C - A) * (D - B) + (G - E) * (H - F)
      intersection = 0
      if min(C, G) >= max(A, E) and min(D, H) >= max(B, F):
          intersection = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F))
      return total_area - intersection
