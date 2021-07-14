#include "usual.h"

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        deque<pair<int, int>> q;
        int n = s.size();
        q.push_back({minJump, maxJump});
        int i = 0;
        while (!q.empty() && q.back().second < n - 1) {
            while (!q.empty() && q.front().second < i)
                q.pop_front();
            if (q.empty())
                return false;
            int beg = q.front().first, end = q.front().second;
            q.pop_front();
            for (i = max(i, beg); i <= end && i + minJump < n; ++i) {
                if (s[i] == '0') {
                    int nbeg = min(i + minJump, n - 1), nend = min(i + maxJump, n - 1);
                    if (!q.empty() && nbeg <= q.back().second)
                        q.back().second = nend;
                    else
                        q.push_back({nbeg, nend});
                }
            }
        }
        return (!q.empty() && q.back().second >= n - 1 && s[n - 1] == '0');
    }
};

int main(int argc, char const *argv[])
{
    string s("00111010");
    int minj = 3, maxj = 5;
    cout << Solution().canReach(s, minj, maxj) << endl;
    return 0;
}
