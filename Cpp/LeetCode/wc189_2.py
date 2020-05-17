class Solution:
    def arrangeWords(self, text: str) -> str:
        str.capitalize()
        l = str.split(' ')
        l.sort(key=len)
        str = " ".join(l)
        str.title()
        return str