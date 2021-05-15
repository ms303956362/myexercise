#include "usual.h"

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> cnt(128);
        for (const auto& c : sentence) {
            ++cnt[c];
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c] == 0)
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
