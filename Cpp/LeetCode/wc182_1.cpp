#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int* cnt = new int[501];
        memset(cnt, 0, 501 * sizeof(int));
        for (auto& v : arr) {
            ++cnt[v];
        }
        int max_lucky = -1;
        for (int i = 1; i != 501; ++i) {
            if (cnt[i] == i && i > max_lucky)
                max_lucky = i;
        }
        return max_lucky;
    }
};