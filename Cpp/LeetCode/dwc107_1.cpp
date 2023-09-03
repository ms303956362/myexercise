#include "usual.h"

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i] == string(words[j].rbegin(), words[j].rend())) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
