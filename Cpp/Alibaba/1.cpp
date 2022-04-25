#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;


int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    unordered_set<string> st;
    while (t-- > 0) {
        string s;
        cin >> s;
        int n = s.size();
        if (n < 6 || n > 12) {
            cout << "illegal length" << endl;
            continue;
        }
        bool ok = true;
        for (const auto& c : s) {
            if (!('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z')) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "illegal charactor" << endl;
            continue;
        }
        if (st.count(s)) {
            cout << "acount existed" << endl;
        } else {
            st.insert(s);
            cout << "registration complete" << endl;
        }
    }
    return 0;
}
