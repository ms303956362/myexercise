#include <iostream>
#include <stack>

using namespace std;

bool check(const string& s) {
    stack<string> st;
    int i = 0, n = s.size();
    while (i < n) {
        if (s[i] != '<') {
            return false;
        }
        ++i;
        if (i >= n) {
            return false;
        }
        int type = 0;
        if (s[i] == '/') {
            type = 1;
            ++i;
        }
        string tag;
        while (i < n && 'a' <= s[i] && s[i] <= 'z') {
            tag.push_back(s[i]);
            ++i;
        }
        if (tag.empty() || i >= n || s[i] != '>') {
            return false;
        }
        ++i;
        if (type == 0) {
            st.push(tag);
        } else {
            if (st.empty() || st.top() != tag) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    if (check(s)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
