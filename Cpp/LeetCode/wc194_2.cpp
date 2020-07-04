#include "usual.h"

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> cnt;
        vector<string> res;
        string new_s;
        for (const auto& s : names) {
            auto p = cnt.find(s);
            if (p != cnt.end()) {
                do {
                    ++p->second;
                    new_s = s + "(" + to_string(p->second) + ")";
                } while (cnt.find(new_s) != cnt.end());
                cnt[new_s] = 0;
                res.push_back(new_s);
            } else {
                cnt[s] = 0;
                res.push_back(s);
            }
        }
        return res;
    }
};