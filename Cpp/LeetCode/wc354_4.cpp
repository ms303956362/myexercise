#include "usual.h"

class TrieNode {
public:
    vector<TrieNode*> children;
    bool is_end;
    TrieNode(): children(26, nullptr), is_end(false) {}
};

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        TrieNode *root = new TrieNode();
        int max_len = 0, n = word.size();
        for (const auto& w : forbidden) {
            max_len = max(max_len, (int)w.size());
            auto p = root;
            for (const auto& c : w) {
                if (p->children[c - 'a'] == nullptr) {
                    p->children[c - 'a'] = new TrieNode();
                }
                p = p->children[c - 'a'];
            }
            p->is_end = true;
        }
        auto check = [&](int i) -> pair<bool, int> {
            auto p = root;
            for (int j = i; j < min(i + max_len, n); ++j) {
                int k = word[j] - 'a';
                if (!(p->children[k])) {
                    return make_pair(true, 0);
                }
                if (p->children[k]->is_end) {
                    return make_pair(false, j - i);
                }
                p = p->children[k];
            }
            return make_pair(true, 0);
        };
        vector<int> dp(n + 1);
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            auto [ok, len] = check(i);
            if (ok) {
                dp[i] = dp[i + 1] + 1;
            } else {
                dp[i] = min(dp[i + 1] + 1, len);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
