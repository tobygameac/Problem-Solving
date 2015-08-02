class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def rob(self, nums):
        ans = []
        for index in range(0, len(nums)):
            money = nums[index]
            if index > 0:
                money = max(money, ans[index - 1])
            if index > 1:
                money = max(money, ans[index - 2] + nums[index])
            ans.append(money)
        if not ans:
            return 0
        return ans[-1]
