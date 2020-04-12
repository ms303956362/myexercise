#include "usual.h"

class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int movingCount(int m, int n, int k) {
        int cnt = 0;
        vector<vector<char>> vst(m, vector<char>(n, 0));
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        vst[0][0] = 1;
        int i, j;
        while (!q.empty()){
            ++cnt;
            auto p = q.front();
            q.pop();
            i = p.first;
            j = p.second;
            if (i-1 >= 0 && !vst[i-1][j] && digitSum(i-1) + digitSum(j) <= k) {
                q.push(make_pair(i-1, j));
                vst[i-1][j] = 1;
            }
            if (j-1 >= 0 && !vst[i][j-1] && digitSum(i) + digitSum(j-1) <= k) {
                q.push(make_pair(i-1, j));
                vst[i][j-1] = 1;
            }
            if (i+1 < m && !vst[i+1][j] && digitSum(i+1) + digitSum(j) <= k) {
                q.push(make_pair(i+1, j));
                vst[i+1][j] = 1;
            }
            if (j+1 < n && !vst[i][j+1] && digitSum(i) + digitSum(j+1) <= k) {
                q.push(make_pair(i, j+1));
                vst[i][j+1] = 1;
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().movingCount(3,1,0) << endl;
    return 0;
}
