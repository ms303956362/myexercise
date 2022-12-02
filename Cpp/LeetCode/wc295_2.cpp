#include "usual.h"

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int i = 0, n = sentence.size();
        string ans;
        while (i < n) {
            int j = i;
            string word;
            while (j < n && sentence[j] != ' ') {
                word.push_back(sentence[j]);
                ++j;
            }
            if (check(word)) {
                long long num = stoll(word.substr(1, j - i - 1));
                double num2 = 1.0 * num * discount / 100;
                char buf[15];
                sprintf(buf, "%.2f", num2);
                word = "$" + string(buf);
            }
            if (j != n) {
                word.push_back(' ');
            }
            ans += word;
        }
        return ans;
    }
    
    bool check(const string& word) {
        if (word.size() <= 1 || word[0] != '$') {
            return false;
        }
        int n = word.size();
        for (int i = 1; i < n; ++i) {
            if (!('0' <= word[i] && word[i] <= '9')) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
