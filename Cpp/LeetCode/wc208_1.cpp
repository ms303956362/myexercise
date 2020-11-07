#include "usual.h"

class Solution {
public:
    int minOperations(vector<string>& logs) {
        unordered_map<string, int> cache;
        int curr = 0;
        for (const auto& s : logs) {
            if (s == "../") {
                if (curr > 0)
                    --curr;
            } else if (s == "./") {
                continue;
            } else {
                if (cache.count(s) != 0) {
                    curr = cache[s];
                } else {
                    cache.insert({s, ++curr});
                }
            }
        }
        return curr;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
