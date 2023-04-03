from typing import List

class Solution:
    def topStudents(self, positive_feedback: List[str], negative_feedback: List[str], report: List[str], student_id: List[int], k: int) -> List[int]:
        scores = {}
        for w in positive_feedback:
            scores[w] = 3
        for w in negative_feedback:
            scores[w] = -1
        ls = []
        for id, r in zip(student_id, report):
            l = r.split()
            s = 0
            for w in l:
                if w in scores:
                    s += scores[w]
            ls.append((s, -id))
        ls.sort(reverse=True)
        ans = []
        for i in range(k):
            s, id = ls[i]
            ans.append(id)
        return ans
        