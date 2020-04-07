#include "usual.h"
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size() + 1, n2 = word2.size() + 1;
        vector<vector<int>> tab(n1, vector<int>(n2, 0));
        for (int i = 1; i < n2; ++i) {
            tab[0][i] = i;
        }
        for (int i = 1; i < n1; ++i) {
            tab[i][0] = i;
        }
        for (int i = 1; i < n1; ++i) {
            for (int j = 1; j < n2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    tab[i][j] = tab[i-1][j-1];
                } else {
                    tab[i][j] = min(tab[i-1][j], tab[i][j-1]) + 1;
                }
            }
        }
        return tab[n1-1][n2-1];
    }
};

int main(int argc, char const *argv[])
{
    cout << Solution().minDistance("horse", "ros") << endl;
    return 0;
}
