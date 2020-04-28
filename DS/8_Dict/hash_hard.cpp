#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Pair {
    int i;
    int n;
    Pair(int idx, int num) : i(idx), n(num) {}
};
bool operator<(const Pair &p1, const Pair &p2) { return p1.n < p2.n; }
bool operator<=(const Pair &p1, const Pair &p2) { return p1.n <= p2.n; }
bool operator==(const Pair &p1, const Pair &p2) { return p1.n == p2.n; }
bool operator>=(const Pair &p1, const Pair &p2) { return p1.n >= p2.n; }
bool operator>(const Pair &p1, const Pair &p2) { return p1.n > p2.n; }

int main(int argc, char const *argv[])
{
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;
    int n, num;
    cin >> n;
    vector<int> times(n, 0), ht(n, -1);
    vector<vector<int>> nbr(n, vector<int>());
    for (int i = 0; i != n; ++i) {
        cin >> num;
        if (num < 0)
            continue;
        times[i] = (i + n - num % n) % n;
        if (!times[i])
            q.push(Pair(i, num));
        else {
            for (int j = num % n; j != i; j = (j + 1) % n)
                nbr[j].push_back(i);
        }
        ht[i] = num;
    }
    bool first = true;
    while (!q.empty()) {
        if (first) {
            first = false;
            cout << q.top().n;
        } else
            cout << " " << q.top().n;
        int i = q.top().i;
        q.pop();
        for (size_t j = 0; j != nbr[i].size(); ++j) {
            if (times[nbr[i][j]] > 0) {
                --times[nbr[i][j]];
                if (!times[nbr[i][j]])
                    q.push(Pair(nbr[i][j], ht[nbr[i][j]]));
            }
        }
    }
    return 0;
}
