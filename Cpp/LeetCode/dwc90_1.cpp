#include "usual.h"

class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> diff;
        for (int i = 0; i < n; ++i) {
            vector<int> curr;
            int m = words[i].size();
            for (int j = 1; j < m; ++j) {
                curr.push_back(words[i][j] - words[i][j - 1]);
            }
            diff.push_back(curr);
        }
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (j == i) {
                    continue;
                }
                if (diff[i] != diff[j]) {
                    ++cnt;
                }
            }
            if (cnt > 1) {
                return words[i];
            }
        }
        return "";
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
