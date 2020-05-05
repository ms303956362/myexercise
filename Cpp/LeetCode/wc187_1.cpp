#include "usual.h"

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> cnt;
        int n = paths.size();
        for (int i = 0; i != n; ++i) {
            auto p = cnt.find(paths[i][0]);
            if (p == cnt.end())
                cnt.insert({paths[i][0], 1});
            else
                ++(p->second);
            cnt.insert({paths[i][1], 0});
        }
        string res;
        for (auto& [s, num] : cnt) {
            if (num == 0) {
                res = s;
                break;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
