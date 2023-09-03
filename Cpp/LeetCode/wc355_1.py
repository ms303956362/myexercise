from typing import *

class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        ans = []
        for word in words:
            l = word.split(separator)
            for w in l:
                if w != "":
                    ans.append(w)
        return ans