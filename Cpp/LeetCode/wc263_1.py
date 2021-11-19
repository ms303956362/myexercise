class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        l = s.split(' ')
        prev = -1
        for w in l:
            ok = True
            for i in range(26):
                c = chr(ord('a') + i)
                if c in w:
                    ok = False
                    break
            if not ok:
                continue
            num = int(w)
            # if not(int(w) == 0 and (w[0] != '0' or len(w) > 1)):
            if num <= prev:
                return False
            prev = num
        return True