#include "usual.h"

class Solution {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> idx;
        int status = 0, num, code;
        int ans = 1;
        idx.insert({0, -1});
        for (int i = 0; i != s.size(); ++i) {
            num = s[i] - '0';
            status ^= (1 << num);
            auto p = idx.find(status);
            if (p == idx.end()) {
                idx.insert({status, i});
            } else {
                ans = max(ans, i - p->second);
            }
            for (int j = 0; j != 11; ++j) {
                code = status ^ (1 << j);
                p = idx.find(code);
                if (p != idx.end())
                    ans = max(ans, i - p->second);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution().longestAwesome("3242415");
    return 0;
}
