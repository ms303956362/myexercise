from typing import List


class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        ans = 0
        for s in sentences:
            l = s.split(' ')
            ans = max(ans, len(l))
        return ans