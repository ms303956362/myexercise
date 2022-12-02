#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < k; ++i) {
        if ('a' <= s[i] && s[i] <= 'z') {
            s[i] = s[i] - 'a' + 'A';
        }
    }
    for (int i = k; i < n; ++i) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    cout << s << endl;
    return 0;
}
