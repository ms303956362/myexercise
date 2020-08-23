#include "usual.h"

class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<int> a(n, 0), l(n, 0), r(n, 0), cnt(n + 1, 0);
        int ans = -1;
        int i;
        for (int j = 0; j != n; ++j) {
            i = arr[j] - 1;
            a[i] = 1;
            l[i] = r[i] = i;
            if (i - 1 >= 0 && a[i - 1] == 1) {
                l[i] = l[i - 1];
                --cnt[i - l[i - 1]];
            }
            if (i + 1 < n && a[i + 1] == 1) {
                r[i] = r[i + 1];
                --cnt[r[i + 1] - i];
            }
            l[r[i]] = l[i];
            r[l[i]] = r[i];
            ++cnt[r[i] - l[i] + 1];
            if (cnt[m] != 0)
                ans = j + 1;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
