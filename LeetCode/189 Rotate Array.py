class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {void} Do not return anything, modify nums in-place instead.
    def rotate(self, nums, k):
        if not nums:
            return
        n = len(nums)
        k = (n - (k % n)) % n
        original_nums = nums[:]
        for index in range(0, n):
            nums[index] = original_nums[(index + k) % n]
