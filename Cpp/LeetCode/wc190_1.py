class Solution:
    def isPrefixOfWord(self, sentence: str, w: str) -> int:
        l = sentence.split(' ')
        for i, word in enumerate(l):
            if len(word) >= len(w) and word[:len(w)] == w:
                return i + 1
        return -1

if __name__ == "__main__":
    print(Solution().isPrefixOfWord("i love eating burger", "burg"))