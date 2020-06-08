#include "usual.h"

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int k;
        for (k = 0; k != wordList.size(); ++k) {
            if (wordList[k] == beginWord){
                wordList.erase(wordList.begin() + k);
                break;
            }
        }
        wordList.push_back(beginWord);
        int n = wordList.size();
        vector<vector<int>> g(n, vector<int>());
        vector<vector<vector<string>>> res(n, vector<vector<string>>());
        vector<bool> vst(n, false), vst1(n, false);
        list<int> q;
        for (int i = 0; i != n - 1; ++i) {
            for (int j = i + 1; j != n; ++j) {
                if (only1Diff(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        q.push_back(n - 1);
        vst[n - 1] = true;
        vst1[n - 1] = true;
        res[n - 1].push_back(vector<string>(1, beginWord));
        while (!q.empty()) {
            int m = q.size();
            for (int k = 0; k != m; ++k) {
                int i = q.front();
                q.pop_front();
                if (wordList[i] == endWord)
                    return res[i];
                for (auto j : g[i]) {
                    if (!vst[j]) {
                        if (!vst1[j]) {
                            q.push_back(j);
                            vst1[j] = true;
                        }
                        for (auto l : res[i]) {
                            l.push_back(wordList[j]);
                            res[j].push_back(l);
                        }
                    }
                }
            }
            for (auto i : q) {
                vst[i] = true;
            }
        }
        return {};
    }

    bool only1Diff(const string& s1, const string& s2) {
        int diff = 0;
        for (int i = 0; i != s1.size(); ++i) {
            if (s1[i] != s2[i])
                ++diff;
        }
        return diff == 1;
    }
};

int main(int argc, char const *argv[])
{
    string beg = "red", end = "tax";
    vector<string> wl = {"ted","tex","red","tax","tad","den","rex","pee"};
    Solution().findLadders(beg, end, wl);
    return 0;
}
