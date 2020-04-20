#include "usual.h"

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        if (croakOfFrogs.size() % 5 != 0)
            return -1;
        int cnt = 0;
        bool ok = false;
        vector<string> pre{"croak", "croa", "cro", "cr", "c"}, post{"", "k", "ak", "oak", "roak"};
        for (int i = 0; i != 5; ++i) {
            auto pos = croakOfFrogs.find(pre[i]);
            ok = false;
            while (pos != string::npos) {
                auto pos2 = croakOfFrogs.find(post[i]);
                if (pos2 != string::npos) {
                    if (!ok) {
                        ++cnt;
                        ok = true;
                    }
                    croakOfFrogs.replace(pos2, post[i].size(), string(post[i].size(), 'd'));
                    croakOfFrogs.replace(pos, pre[i].size(), string(pre[i].size(), 'd'));
                } else {
                    return -1;
                }
                pos = croakOfFrogs.find(pre[i]);
            }
        }
        return cnt;
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().minNumberOfFrogs("croakcroa") << endl;
    return 0;
}
