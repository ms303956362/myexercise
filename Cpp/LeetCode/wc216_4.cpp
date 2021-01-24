#include "usual.h"

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int max_req = 0, sum_act = 0;
        for (const auto& v : tasks) {
            max_req = max(max_req, v[1]);
            sum_act += v[0];
        }
        int ans = max(max_req, sum_act), e = ans;
        sort(tasks.begin(), tasks.end(), [](const vector<int> &vl, const vector<int> &vr) {
            return (vl[1] - vl[0] > vr[1] - vr[0]) || (vl[1] - vl[0] == vr[1] - vr[0] && vl[0] > vr[0]);
        });
        for (const auto& v : tasks) {
            ans += e - max(e, v[1]);
            e = max(e, v[1]);
            e -= v[0];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
