#include "usual.h"

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for (int i = 0; i != words.size(); ++i) {
            for (int j = 0; j != words.size(); ++j) {
                if (j == i)
                    continue;
                if (words[j].find(words[i]) != string::npos) {
                    res.push_back(words[i]);
                    break;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> sv{"mass", "as", "hero", "superhero"};
    Solution().stringMatching(sv);
    return 0;
}
