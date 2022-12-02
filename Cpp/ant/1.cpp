#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    string curr(x, 'a');
    int t = 25;
    while (t--) {
        bool ok = false;
        string nxt;
        int n = curr.size();
        int i = 0;
        for (; i < n - 1; i += 2) {
            if (curr[i] != curr[i + 1]) {
                break;
            }
            ok = true;
            nxt.push_back(curr[i] + 1);
        }
        while (i < n) {
            nxt.push_back(curr[i]);
            ++i;
        }
        if (!ok) {
            break;
        }
        curr = nxt;
    }
    cout << curr << endl;
    return 0;
}
