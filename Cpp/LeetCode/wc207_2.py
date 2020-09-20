class Solution:
    def maxUniqueSplit(self, ss: str) -> int:
        def dfs(i: int, s: str, st: set):
            if i == len(s):
               return len(st)
            ans = 0
            for j in range(i + 1, len(s) + 1):
                if not s[i:j] in st:
                    st.add(s[i:j])
                    ans = max(ans, dfs(j, s, st))
                    st.remove(s[i:j])
            return ans
        
        sst = set([])
        return dfs(0, ss, sst)
