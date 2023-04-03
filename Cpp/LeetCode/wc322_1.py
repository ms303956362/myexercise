class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        l = sentence.split()
        for i in range(len(l) - 1):
            if sentence[i][-1] != sentence[i + 1][0]:
                return False
        return sentence[0][0] == sentence[-1][-1]