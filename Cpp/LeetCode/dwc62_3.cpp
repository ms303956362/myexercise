#include "usual.h"

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = 0, h = answerKey.size(), n = answerKey.size();
        while (l <= h) {
            int m = (l + h) / 2;
            int cntT = 0;
            for (int i = 0; i < m; ++i) {
                if (answerKey[i] == 'T')
                    ++cntT;
            }
            int t = min(cntT, m - cntT);
            for (int i = m; i < n; ++i) {
                if (answerKey[i - m] == 'T')
                    --cntT;
                if (answerKey[i] == 'T')
                    ++cntT;
                t = min(t, min(m - cntT, cntT));
            }
            if (t <= k)
                l = m + 1;
            else
                h = m - 1;
        }
        return h;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
