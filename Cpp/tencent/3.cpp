#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    deque<int> q;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
             if (q.back() > q.front()) {
                cout << q.back() << " ";
                q.pop_back();
             } else {
                cout << q.front() << " ";
                q.pop_front();
             }
        } else {
            if (q.back() < q.front()) {
                cout << q.back() << " ";
                q.pop_back();
             } else {
                cout << q.front() << " ";
                q.pop_front();
             }
        }
    }
    return 0;
}
