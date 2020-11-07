#include "usual.h"

class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> times;
        vector<string> ans;
        int n = keyName.size();
        for (int i = 0; i != n; ++i) {
            int t = (keyTime[i][0] - '0') * 1000 + (keyTime[i][1] - '0')  * 100 + (keyTime[i][3] - '0')  * 10 + (keyTime[i][4] - '0');
            times[keyName[i]].push_back(t);
        }
        for (auto& [name, ts] : times) {
            sort(ts.begin(), ts.end());
            int i = 0, j = 1, m = ts.size();
            while (j < m) {
                while (i < j && ts[j] - ts[i] > 100)
                    ++i;
                if (j - i >= 2) {
                    ans.push_back(name);
                    break;
                }
                ++j;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> keyName{"daniel", "daniel", "daniel", "luis", "luis", "luis", "luis"}, keyTime { "10:00", "10:40", "11:00", "09:00", "11:00", "13:00", "15:00" };
    Solution().alertNames(keyName, keyTime);
    return 0;
}
