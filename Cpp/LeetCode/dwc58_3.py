from functools import lru_cache
from typing import List

class Solution:
    def minSpaceWastedKResizing(self, nums: List[int], k: int) -> int:
        n = len(nums)

        @lru_cache(None)
        def f(i, curr, t):
            if t < 0:
                return 1e10
            if i == n:
                return 0
            if curr == nums[i]:
                return f(i + 1, curr, t)
            else:
                for num in nums:
                    if num >= nums[i]:
                        if curr < nums[i]:
                            return f(i + 1, num, t - 1) + num - nums[i]
                        else:
                            return min(f(i + 1, curr, t) + curr - nums[i], f(i + 1, num, t - 1) + num - nums[i])
        ans = 1e11
        for num in nums:
            ans = min(ans, f(0, num, k))
        return ans

a = [10,14,49,22,7,6,25]
k = 2
Solution().minSpaceWastedKResizing(a, k)
