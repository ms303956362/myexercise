class Solution:
    def capitalizeTitle(self, title: str) -> str:
        ans = []
        l = title.split(' ')
        for w in l:
            if len(w) > 2:
                w = w.capitalize()
            else:
                w = w.lower()
            ans.append(w)
        return " ".join(ans)
