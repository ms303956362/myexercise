class Solution:
    def sortSentence(self, s: str) -> str:
        words = s.split(' ')
        ans = []
        for i in range(len(words)):
            for word in words:
                if ord(word[-1]) - ord('0') == i + 1:
                    ans.append(word)
                    break
        return ' '.join(ans)

Solution().sortSentence("is2 sentence4 This1 a3")
