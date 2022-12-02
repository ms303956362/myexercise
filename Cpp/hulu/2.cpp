#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
using namespace std;

pair<int, string> parse(const string& s, int& i) {
    int n = s.size();
    int type = 0;
    ++i;
    if (s[i] == '/') {
        ++i;
        type = 1;
    }
    string tag;
    while (i < n && s[i] != '>') {
        tag.push_back(s[i]);
        ++i;
    }
    ++i;
    if (!tag.empty() && tag.back() == '/') {
        type = 2;
        tag.pop_back();
    }
    return make_pair(type, tag);
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int n = s.size();
    stack<string> st;
    int i = 0;
    map<int, vector<string>> level;
    while (i < n) {
        auto p = parse(s, i);
        int type = p.first;
        string tag = p.second;
        if (type == 0) {
            st.push(tag);
        } else if (type == 1) {
            st.pop();
            level[st.size()].push_back(tag);
        } else {
            level[st.size()].push_back(tag);
        }
    }
    for (const auto& p : level) {
        for (const auto& tag : p.second) {
            cout << tag << " ";
        }
    }
    cout << endl;
    return 0;
}
