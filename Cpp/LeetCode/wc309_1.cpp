#include "usual.h"

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.size();
        vector<int> dis(26);
        for (int i = 0; i < n; ++i) {
            if (dis[s[i] - 'a'] == 0) {
                for (int j = i + 1; j < n; ++j) {
                    if (s[j] == s[i]) {
                        dis[s[i] - 'a'] = j - i - 1;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (dis[i] > 0 && dis[i] != distance[i]) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
