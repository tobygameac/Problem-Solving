class Solution:
    # @param {integer[]} nums
    # @param {integer} k
    # @return {boolean}
    def containsNearbyDuplicate(self, nums, k):
        d = dict()
        for i in range(0, len(nums)):
            last_index = d.get(nums[i])
            if last_index != None and (i - last_index) <= k:
                return True
            d[nums[i]] = i
        return False
