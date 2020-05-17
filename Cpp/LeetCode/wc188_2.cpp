#include "usual.h"

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0, Xor = 0;
        vector<int> pre(n + 1, 0);
        pre[0] = 0;
        for (int i = 1; i != n + 1; ++i) {
            Xor ^= arr[i - 1];
            pre[i] = Xor;
        }
        for (int i = 0; i != n - 1; ++i)
        {
            for (int j = i + 1; j != n; ++j)
            {
                for (int k = j; k != n; ++k)
                {
                    if (pre[j]^pre[i] == pre[k + 1]^pre[j])
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> t{2, 3, 1, 6, 7};
    cout << Solution().countTriplets(t) << endl;
    return 0;
}
