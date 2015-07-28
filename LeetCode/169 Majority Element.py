class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def majorityElement(self, nums):
        sorted_nums = sorted(nums)

        previous_num = sorted_nums[0] - 1
        current_num_count = 0
        for n in sorted_nums:
            if n == previous_num:
                current_num_count = current_num_count + 1
                if current_num_count >= (len(nums) / 2):
                    return n
            else:
                current_num_count = 0
            previous_num = n

        return sorted_nums[-1]
