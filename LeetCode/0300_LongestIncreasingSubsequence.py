class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        lengths = [1] * len(nums)
        for i in range(len(nums)):
            for j in range(0, i):
                if nums[j] < nums[i]:
                    lengths[i] = max(lengths[i], lengths[j] + 1)
        
        return max(lengths)