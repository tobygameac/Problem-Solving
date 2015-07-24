class Solution:
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        ans = []
        if len(nums) != 0:
            begin_value = nums[0]
        for i in range(1, len(nums) + 1):
            if (i == len(nums)) or (nums[i] != nums[i - 1] + 1):
                if begin_value == nums[i - 1]:
                    ans.append(str(begin_value))
                else:
                    ans.append(str(begin_value) + "->" + str(nums[i - 1]))
                if i != len(nums):
                  begin_value = nums[i]
        return ans
