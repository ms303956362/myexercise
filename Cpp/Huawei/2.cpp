#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int n = s.size();
    int m;
    cin >> m;
    vector<int> tags(m);
    for (int i = 0; i < m; ++i) {
        cin >> tags[i];
    }
    unordered_map<char, int> num, offsets, lens;
    for (char c = '0'; c <= '9'; ++c) {
        num[c] = c - '0';
    }
    num['A'] = 10;
    num['B'] = 11;
    num['C'] = 12;
    num['D'] = 13;
    num['E'] = 14;
    num['F'] = 15;
    int i = 0;
    while (i < n - 3) {
        int tag = num[s[i]] * 16 + num[s[i + 1]];
        i += 2;
        int len = num[s[i]] * 16 + num[s[i + 1]];
        i += 2;
        if (i + 2 * len > n) {
            break;
        }
        offsets[tag] = i / 2;
        lens[tag] = len;
        i += len;
    }
    for (const auto& tag : tags) {
        if (offsets.count(tag)) {
            cout << lens[tag] << " " << offsets[tag] << endl;
        } else {
            cout << 0 << " " << 0 << endl;
        }
    }
    return 0;
}
