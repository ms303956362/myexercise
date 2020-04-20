#include "usual.h"

class Solution {
public:
    int minJump(vector<int>& jump) {
        int n = jump.size();
        vector<int> jf(n, 0), max_jf(n, 0);
        for (int i = 0; i != n; ++i) {
            jf[i] = jump[i] + i;
            max_jf[i] = jf[i];
        }
        for (int i = 1; i != n; ++i) {
            if (max_jf[i-1] > max_jf[i])
                max_jf[i] = max_jf[i - 1];
        }
        int k = 0;
        int i = 0;
        while (i < n) {
            if (jf[i] == max_jf[i]) {
                i = jf[i];
                ++k;
            } else {
                if (jf[jf[i]] >= max_jf[i]) {
                    i = jf[i];
                    ++k;
                } else {
                    i = max_jf[i];
                    k += 2;
                }
            }
        }
        return k;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v{2, 5, 1, 1, 1, 1};
    cout << Solution().minJump(v) << endl;
    return 0;
}
