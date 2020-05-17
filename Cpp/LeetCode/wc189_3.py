class Solution:
    def peopleIndexes(self, fc):
        n = len(fc)
        res = []
        for i in range(n):
            ok = True
            for j in range(n):
                if i != j and set(fc[i]) & set(fc[j]) == set(fc[i]):
                    ok = False
                    break
            if ok:
                res.append(i)
        return res

Solution().peopleIndexes([["leetcode", "google", "facebook"], ["google", "microsoft"], ["google", "facebook"], ["google"], ["amazon"]])
