#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    static int numTeams(vector<int>& rating) {
        if (rating.size() < 3)
            return 0;
        int cnt = 0, n = rating.size();
        int *g = new int[n];
        int *l = new int[n];
        for (int i = 0; i != n; ++i) {
            g[i] = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (rating[i] > rating[j]) {
                    ++g[i];
                    cnt += g[j];
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            l[i] = 0;
            for (int j = i + 1; j < n; ++j) {
                if (rating[i] > rating[j]) {
                    ++l[i];
                    cnt += l[j];
                }
            }
        }
        // for (int i = 0; i != n; ++i) {
        //     if (g[i] >= 2)
        //         cnt += g[i] * (g[i] - 1) / 2;
        //     if (l[i] >= 2)
        //         cnt += l[i] * (l[i] - 1) / 2;
        // }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{2, 5, 3, 4, 1};
    int cnt = Solution::numTeams(v);
    cout << cnt;
    return 0;
}
