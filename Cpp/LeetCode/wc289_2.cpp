#include "usual.h"

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        int i = 0, n = tasks.size(), ans = 0;
        while (i < n) {
            int j = i + 1;
            while (j < n && tasks[j] == tasks[i]) {
                ++j;
            }
            int cnt = j - i;
            if (cnt == 1) {
                return -1;
            }
            if (cnt % 3 == 0) {
                ans += cnt / 3;
            } else {
                ans += cnt / 3 + 1;
            }
            i = j;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
