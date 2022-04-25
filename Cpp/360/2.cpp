#include <iostream>
#include <unordered_set>
#include <string>
#include <cstdio>
using namespace std;

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    unordered_set<string> s1, s2, s3;
    for (int i = 0; i < n1; ++i) {
        string s;
        cin >> s;
        s1.insert(s);
    }
    for (int i = 0; i < n2; ++i) {
        string s;
        cin >> s;
        s2.insert(s);
    }
    for (int i = 0; i < n3; ++i) {
        string s;
        cin >> s;
        s3.insert(s);
    }
    int m;
    cin >> m;
    char ch;
    scanf("%c", &ch);
    auto check = [&](const string& s) {
   		int n = s.size();
        int i = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] != ' ') {
                ++j;
            }
            string word = s.substr(i, j - i);
            if (s1.count(word)) {
                // if (cnt2 > 0 || cnt3 > 0) {
                //     return false;
                // }
                ++cnt1;
            } else if (s2.count(word)) {
                // if (cnt3 > 0) {
                //     return false;
                // }
                ++cnt2;
            } else if (s3.count(word)) {
                ++cnt3;
            } else {
                throw "hello";
            }
            i = j + 1;
        }
        return cnt1 >= 1 && cnt2 == 1;
    };
    for (int i = 0; i < m; ++i) {
        string s;
        getline(cin, s);
        if (check(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}