#include "usual.h"

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size();
        unordered_map<string, int> cnt;
        for (int i = 0; i < n; ++i) {
            int j = 0, k = 0, m = messages[i].size();
            while (j < m) {
                if (messages[i][j] == ' ') {
                    cnt[senders[i]] += 1;
                }
                ++j;
            }
            cnt[senders[i]] += 1;
        }
        int max_cnt = 0;
        string ans;
        for (const auto& [name, c] : cnt) {
            if (c > max_cnt || c == max_cnt && name > ans) {
                ans = name;
                max_cnt = c;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
