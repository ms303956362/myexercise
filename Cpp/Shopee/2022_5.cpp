#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, t;
    cin >> n >> t;
    unordered_map<string, long long> balance;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        long long b;
        cin >> b;
        balance[s] = b;
    }
    for (int i = 0; i < t; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        long long money;
        cin >> money;
        if (money <= balance[s1]) {
            balance[s1] -= money;
            balance[s2] += money;
        }
    }
    map<string, long long> ans(balance.begin(), balance.end());
    for (const auto& [s, b] : ans) {
        cout << s << " " << b << endl;
    }
    return 0;
}
