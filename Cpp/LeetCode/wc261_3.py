from typing import List
from functools import lru_cache

class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        @lru_cache()
        def dfs(cnt0, cnt1, cnt2, curr, isbob) -> bool:
            if curr == 0:
                return False
            if cnt0 == 0 and cnt1 == 0 and cnt2 == 0:
                return isbob
            if curr == 1:
                if cnt1 == 0:
                    if cnt2 == 0:
                        if cnt0 % 2:
                            return not isbob
                        else:
                            return isbob
                    return not cnt0 % 2
                if cnt0 == 0:
                    return cnt1 > cnt2
            elif curr == 2:
                if cnt2 == 0:
                    if cnt1 == 0:
                        if cnt0 % 2:
                            return not isbob
                        else:
                            return isbob
                    return not cnt0 % 2
                if cnt0 == 0:
                    return cnt1 < cnt2
            ok1, ok2 = True, True
            if curr == 1:
                if cnt0 > 0:
                    ok1 = dfs(cnt0 - 1, cnt1, cnt2, curr, 1 - isbob)
                if cnt1 > 0:
                    ok2 = dfs(cnt0, cnt1 - 1, cnt2, 3 - curr, 1 - isbob)
                return not ok1 or not ok2
            else:
                if cnt0 > 0:
                    ok1 = dfs(cnt0 - 1, cnt1, cnt2, curr, 1 - isbob)
                if cnt2 > 0:
                    ok2 = dfs(cnt0, cnt1, cnt2 - 1, 3 - curr, 1 - isbob)
                return not ok1 or not ok2
        
        cnt0, cnt1, cnt2 = 0, 0, 0
        for s in stones:
            if s % 3 == 0:
                cnt0 += 1
            elif s % 3 == 1:
                cnt1 += 1
            else:
                cnt2 += 1
        ok1, ok2 = True, True
        if cnt1 > 0:
            ok1 = dfs(cnt0, cnt1 - 1, cnt2, 1, 1)
        if cnt2 > 0:
            ok2 = dfs(cnt0, cnt1, cnt2 - 1, 2, 1)
        return not ok1 or not ok2

# [413,138,207,13,441,63,23,411,400,339,483,346,154,284,319,185,93,87,253,51,314,343,120,170,112,329,278,47,443,286,359,324,202,154,179,313,265,147,66,200,469,301,126,399,194,96,278,254,260,140,421,383,103,4,234,284,187,159,94,476,403,160,395,118,360,17,316,473,230,188,348,226,383,25,137,75,406,495,481,101,146,212,183,333,193,494,145,195,338,497,492,336,168,213,155,19,179,274,161,411,68,104,359,17,297,210,437,88,39,410,251,151,81,308,328,477,27,109,277,416,99,60,452,457,291,487,130,68,386,365,340,280,432,185,103,157,380,394,14,188,104,143,297,292,205,452,359,223,140,373,256,426,374,163,101,198,429,83,297,469,275,478,140,9,35,407,440,28,66,48,334,81,100,35,151,390,112,342,144,127,303,72,20,111,15,360,147,375,212,200,478,23,220,35,346,275,305,310,34,217,304,406,41,343,311,414,164,487,328,93,61,486,376,362,108,343,4,331,397,71,68,110,111,99,406,1,216,278,28,44,426,53,132,355,473,422,93,444,167,191,424,78,444,373,279,41,196,131,157,329,57,20,466,12,483,2,75,109,491,9,247,145,179,164,185,159,131,481,492,97,244,76,224,376,326,70,24,214,483,242,380,115,418,71,246,93,88,3,312,71,25,378,212,149,144,95,12,375,344,199,317,228,87,359,467,376,491,224,53,378,348,233,99,477,382,476,112,124,155,74,485,291,425,311,364,251,238,137,64,419,292,206,70,99,271,477,104,88,32,231,59,134,43,257,245,359,22,62,115,158,72,479,72,79,20,36,497,101,74,403,101,336,430,25,65,48,269,66,428,70,136,360,100,227,34,360,170,436,452,36,404,285,408,144,222,290,73,178,339,113,85,193,5,58,45,402,376,137,260,88,151,88,6,114,29,25,303,64,327,35,165,52,432,409,197,19,420,240,78,477,425,296,65,96,87,28,361,288,170,92,458,122,65,449,125,41,22,315,306,49,256,198,347,307,347,266,166,370,253,125,153,252,239,476,219,402,248,454,147,359,247,364,303,150,69,324,401,92,54,324,189,255,216,393,383,365,461,430,367,82,17,252,223,19,437,6,235,442,241,145,381,121,89,348,288,182,417,104,56,80,233,380,360,252,46,195,419,414,234,466,27,339,151,64,68,381,22,156,314,1,345,84,226,109,191,278,93,355,186,166,477,102,287,459,152,55,200,128,258,137,370,499,324,301,441,140,454,77,405,358,276,350,358,456,101,401,224,88,476,317,53,97,488,342,368,154,197,127,193,355,490,483,409,380,115,40,37,216,276,401,481,403,73,209,419,231,68,179,134,391,366,282,317,196,179,465,29,320,181,334,137,63,474,122,117,22,313,149,263,222,219,279,200,305,20,249,412,132,184,248,31,289,371,153,94,142,77,149,414,408,285,317,100,128,72,120,34,187,39,414,372,186,103,69,24,457,170,361,358,420,205,385,52,226,334,121,259,343,500,16,60,156,486,100,406,476,348,497,351,417,470,180,297,271,366,445,85,44,262,180,119,337,408,384,264,44,78,184,431,64,424,20,480,208,247,277,4,384,79,141,363,47,368,25,345,402,59,494,305,129,48,354,136,499,500,54,64,268,151,291,11,272,395,209,410,420,275,273,448,160,83,338,247,58,279,193,378,364,363,12,189,465,376,221,334,8,215,335,284,213,204,260,60,34,258,337,324,423,50,102,419,128,414,447,285,472,234,393,133,476,300,244,33,227,441,123,446,185,195,20,321,116,313,243,261,161,299,449,419,118,317,73,102,223,138,422,462,374,398,329,499,143,223,378,9,380,405,423,183,418,38,192,102,91,320,363,243,129,264,147,115,82,406,197,275,414,267,48,61,145,352,68,57,23,193,258,142,117,237,364,390,165,380,207,365,35,268,290,58,53,392,471,417,389,396,240,11,360,312,471,77,21,204,255,172,80,470,346,466,277,285,176,228,27,475,52,141,472,18,97,463,382,201,112,428,134,439,270,265,163,241,168,147,338,45,175,467,74,139,192,499,392,131,131,448,147,344,167,331,481,162,371,43,10,270,125,135,205,215,149,350,111,260,26,47,441,112,40,477,433,235,479,267,249,182,201,435,366,154,342,346,260,152,27]