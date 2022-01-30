#include "usual.h"

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        long long n = arr.size();
        unordered_map<int, vector<long long>> m, pre;
        for (long long i = 0; i < n; ++i) {
            m[arr[i]].push_back(i);
            if (!pre.count(arr[i])) {
                pre[arr[i]].push_back(0);
            }
            pre[arr[i]].push_back(pre[arr[i]].back() + i);
        }
        vector<long long> ans;
        for (long long i = 0; i < n; ++i) {
            long long j = lower_bound(m[arr[i]].begin(), m[arr[i]].end(), i) - m[arr[i]].begin();
            int a = j * m[arr[i]][j] - pre[arr[i]][j] + (pre[arr[i]].back() - pre[arr[i]][j]) - ((long long)m[arr[i]].size() - j) * m[arr[i]][j];
            // cout << i << " " << a << endl;
            ans.push_back(a);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
