#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

inline bool is_palindromic(const string& s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j])
            return false;
        ++i;
        --j;
    }
    return true;
}

void string_add(string& s1, string& s2) {
    char c = 0;
    int n = s1.size();
    for (int i = 0; i < n; ++i) {
        int s = (s1[i] - '0') + (s2[i] - '0') + c;
        s1[i] = s % 10 + '0';
        c = s / 10;
    }
    if (c == 1)
        s1.push_back('1');
    reverse(s1.begin(), s1.end());
}

int main(int argc, char const *argv[])
{
    char *cs = (char *)malloc(1005 * sizeof(char));
    scanf("%s", cs);
    string s1(cs);
    int i;
    if (is_palindromic(s1))
        printf("%s is a palindromic number.", s1.c_str());
    else {
        for (i = 0; i < 10; ++i) {
            string s2(s1);
            reverse(s1.begin(), s1.end());
            printf("%s + %s = ", s2.c_str(), s1.c_str());
            string_add(s1, s2);
            printf("%s\n", s1.c_str());
            if (is_palindromic(s1)) {
                printf("%s is a palindromic number.", s1.c_str());
                break;
            }
        }
        if (i >= 10)
            printf("Not found in 10 iterations.");
    }
    free(cs);
    return 0;
}
