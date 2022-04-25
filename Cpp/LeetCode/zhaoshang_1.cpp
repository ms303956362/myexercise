#include "usual.h"

class Solution {
public:
    string deleteText(string article, int index) {
        if (article[index] == ' ') {
            return article;
        }
        int i = 0, n = article.size();
        vector<string> words;
        while (i < n) {
            int j = i + 1;
            while (j < n && article[j] != ' ') {
                ++j;
            }
            if (!(i <= index && index < j)) {
                words.push_back(article.substr(i, j - i));
            }
            i = j + 1;
        }
        string ans;
        for (const auto& w : words) {
            ans += w + " ";
        }
        if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
