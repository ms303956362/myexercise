class Solution:
    def truncateSentence(self, s: str, k: int) -> str:
        l = s.split(' ')
        return ''.join(l[:k])
