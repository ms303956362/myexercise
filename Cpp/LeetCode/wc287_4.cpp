#include "usual.h"

class TrieNode {
public:
    bool isend;
    vector<TrieNode *> children;
    TrieNode(): isend(false), children(26, nullptr) {}
};

class Encrypter {
    unordered_map<string, vector<char>> v2k;
    unordered_map<char, string> k2v;
    TrieNode *root;

public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary): root(new TrieNode()) {
        int m = keys.size();
        for (int i = 0; i < m; ++i) {
            v2k[values[i]].push_back(keys[i]);
            k2v[keys[i]] = values[i];
        }
        for (const auto& word : dictionary) {
            auto p = root;
            for (const auto& c : word) {
                if (!p->children[c - 'a']) {
                    p->children[c - 'a'] = new TrieNode();
                }
                p = p->children[c - 'a'];
            }
            p->isend = true;
        }
    }
    
    string encrypt(string word1) {
        string ans;
        for (const auto& c : word1) {
            ans += k2v[c];
        }
        return ans;
    }
    
    int decrypt(string word2) {
        int n = word2.size() / 2;
        vector<vector<char>> candidates(n);
        for (int i = 0; i < n; ++i) {
            string value(2, 'a');
            value[0] = word2[2 * i];
            value[1] = word2[2 * i + 1];
            candidates[i] = v2k[value];
        }
        int ans = 0;
        function<void(TrieNode *, int)> dfs = [&](TrieNode *p, int i) {
            if (i == n) {
                if (p->isend) {
                    ++ans;
                }
                return;
            }
            for (const auto& c : candidates[i]) {
                if (p->children[c - 'a']) {
                    dfs(p->children[c - 'a'], i + 1);
                }
            }
        };
        dfs(root, 0);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
