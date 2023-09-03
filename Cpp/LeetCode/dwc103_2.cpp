#include "usual.h"

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(n);
            for (int j = 0; j <= i; ++j) {
                ++cnt[A[j] - 1];
                ++cnt[B[j] - 1];
            }
            for (int j = 0; j < n; ++j) {
                if (cnt[j] == 2) {
                    ++ans[i];
                }
            }
        }
        return ans;
    }
};