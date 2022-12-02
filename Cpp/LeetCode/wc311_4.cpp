#include "usual.h"

class TrieNode {
public:
    int cnt;
    vector<TrieNode*> children;
    TrieNode(): cnt(1), children(26, nullptr) {}
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const auto& w : words) {
            auto p = root;
            for (const auto& c : w) {
                if (!p->children[c - 'a']) {
                    p->children[c - 'a'] = new TrieNode();
                } else {
                    ++p->children[c - 'a']->cnt;
                }
                p = p->children[c - 'a'];
            }
        }
        vector<int> ans;
        for (const auto& w : words) {
            auto p = root;
            int sum = 0;
            for (const auto& c : w) {
                sum += p->children[c - 'a']->cnt;
                p = p->children[c - 'a'];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
