#include "usual.h"

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<string> sv, tv;
        for (auto& v : orders) {
            auto ps = find(sv.begin(), sv.end(), v[2]);
            if (ps == sv.end())
                sv.push_back(v[2]);
            auto pt = find(tv.begin(), tv.end(), v[1]);
            if (pt == tv.end())
                tv.push_back(v[1]);
        }
        sort(sv.begin(), sv.end());
        sort(tv.begin(), tv.end(), [](const string &s1, const string &s2) { return stoi(s1) < stoi(s2); });
        vector<vector<string>> res(tv.size() + 1, vector<string>(sv.size() + 1, "0"));
        res[0][0] = "Table";
        for (unsigned int i = 1; i != tv.size() + 1; ++i) {
            res[i][0] = tv[i - 1];
        }
        for (unsigned int i = 1; i != sv.size() + 1; ++i) {
            res[0][i] = sv[i - 1];
        }
        for (auto& v : orders) {
            auto pt = find(tv.begin(), tv.end(), v[1]);
            auto ps = find(sv.begin(), sv.end(), v[2]);
            int i = pt - tv.begin() + 1, j = ps - sv.begin() + 1;
            res[i][j] = to_string(stoi(res[i][j]) + 1);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<string>> s{
        {"David", "3", "Ceviche"}, {"Corina", "10", "Beef Burrito"}, {"David", "3", "Fried Chicken"}, {"Carla","5","Water"},{"Carla","5","Ceviche"},{"Rous","3","Ceviche"}};
    Solution().displayTable(s);
    return 0;
}
