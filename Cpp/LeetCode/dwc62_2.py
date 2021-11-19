from typing import List


class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        ns = [int(s) for s in nums]
        t = int(target)
        n = len(nums)
        ans = 0
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                if nums[i] + nums[j] == target:
                    ans += 1
        return ans