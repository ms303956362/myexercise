#include "usual.h"

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> ans(m), colors(n);
        for (int k = 0; k < m; ++k) {
            if (k > 0) {
                ans[k] = ans[k - 1];
            }
            int i = queries[k][0], c = queries[k][1];
            if (colors[i] == 0) {
                if (i < n - 1 && colors[i + 1] == c) {
                    ++ans[k];
                }
                if (i > 0 && colors[i - 1] == c) {
                    ++ans[k];
                }
            } else {
                if (i < n - 1) {
                    int a1 = (c == colors[i + 1]), a2 = (colors[i] == colors[i + 1]);
                    ans[k] += a1 - a2;
                }
                if (i > 0) {
                    int a1 = (c == colors[i - 1]), a2 = (colors[i] == colors[i - 1]);
                    ans[k] += a1 - a2;
                }
            }
            colors[i] = c;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
