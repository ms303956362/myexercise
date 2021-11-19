#include "usual.h"

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size(), n1 = (n + rows - 1) / rows * rows - n;
        if (n == 0)
            return "";
        encodedText += string(n1, ' ');
        n = encodedText.size();
        int cols = n / rows;
        vector<string> m;
        for (int i = 0; i < n; i += cols) {
            m.push_back(encodedText.substr(i, i + cols));
        }
        int dmax = 0;
        for (int i = 0; i < rows; ++i) {
            if (m[i][cols - 1] != ' ') {
                dmax = cols - i;
                break;
            }
        }
        string ans;
        for (int d = 0; d <= dmax; ++d) {
            for (int r = 0, c = d; r < rows && c < cols; ++r, ++c) {
                ans.push_back(m[r][c]);
            }
        }
        while (ans.back() == ' ')
            ans.pop_back();
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    string s("ch   ie   pr");
    int r = 3;
    Solution().decodeCiphertext(s, r);
    return 0;
}
