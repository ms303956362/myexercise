#include "usual.h"

class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int n = message.size(), l = 1, h = 1e4 + 5;
        int ans = -1;
        auto len_num = [&](int num) {
            int ret = 0;
            while (num > 0) {
                ++ret;
                num /= 10;
            }
            return ret;
        };
        auto check = [&](int m) -> int {
            int j = 0;
            for (int i = 1; i < m; ++i) {
                int delta = limit - 3 - len_num(i) - len_num(m);
                if (delta < 0) {
                    return 1;
                }
                j += delta;
            }
            if (n - j + 3 + len_num(m) + len_num(m) > limit) {
                return -1;
            }
            return 0;
        };
        while (l <= h) {
            int m = (l + h) / 2;
            int code = check(m);
            if (code >= 0) {
                if (code == 0) {
                    ans = m;
                }
                h = m - 1;
            } else {
                l = m + 1;
            }
        }
        if (ans < 0) {
            return {};
        }
        vector<string> ret;
        int j = 0;
        for (int i = 1; i <= ans; ++i) {
            int delta = limit - 3 - len_num(i) - len_num(ans);
            ret.push_back(message.substr(j, delta) + "<" + to_string(i) + "/" + to_string(ans) + ">");
            j += delta;
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> ret = Solution().splitMessage(string(1073, 'a'), 10);
    cout << ret.size() << endl;
    return 0;
}
