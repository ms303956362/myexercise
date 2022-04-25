#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    vector<string> nums;
    while (i < n) {
        if ('0' <= s[i] && s[i] <= '9') {
            int j = i;
            string num;
            while (j < n && '0' <= s[j] && s[j] <= '9') {
                num.push_back(s[j]);
                ++j;
            }
            nums.push_back(num);
            i = j;
        } else {
            ++i;
        }
    }
    auto cmp = [&](const string &ls, const string &rs)
    {
        return ls.size() < rs.size() || (ls.size() == rs.size() && ls < rs);
    };
    sort(nums.begin(), nums.end(), cmp);
    for (const auto& s : nums) {
        cout << s << endl;
    }
    return 0;
}
