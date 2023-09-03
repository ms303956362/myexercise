#include "usual.h"

class Solution {
public:
    int getNandResult(int k, vector<int>& arr, vector<vector<int>>& operations) {
        int n = arr.size();
        vector<set<int>> idx0(k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if ((arr[i] & (1 << j)) == 0) {
                    idx0[j].insert(i);
                }
            }
        }
        int ans = 0;
        for (const auto& op : operations) {
            int type = op[0];
            if (type == 0) {
                int i = op[1], y = op[2];
                for (int j = 0; j < k; ++j) {
                    if ((y & (1 << j)) == 0) {
                        idx0[j].insert(i);
                    } else if (idx0[j].count(i)) {
                        idx0[j].erase(i);
                    }
                }
            } else {
                int res = 0, x = op[1], y = op[2];
                for (int j = 0; j < k; ++j) {
                    if (idx0[j].empty()) {
                        if (n % 2 == 1 && x % 2 == 1) {
                            y ^= (1 << j);
                        }
                        res |= y & (1 << j);
                    } else if ((n - *idx0[j].rbegin() - 1) % 2 == 0) {
                        res |= (1 << j);
                    }
                }
                ans ^= res;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int k = 4;
    vector<int> a{4,6,4,7,10,9,11};
    vector<vector<int>> op{{1,5,7},{1,7,14},{0,6,7},{1,6,5}};
    Solution().getNandResult(k, a, op);
    return 0;
}
