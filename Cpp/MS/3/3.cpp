#include "usual.h"

tuple<long long, long long, long long> dfs(int u, int f, vector<vector<int>>& g) {
    long long cnt_people = 1, cnt_fuel = 0;
    for (const auto& v : g[u]) {
        if (v == f) {
            continue;
        }
        auto t = dfs(v, u, g);
        auto cnt_p = get<0>(t);
        auto cnt_c = get<1>(t);
        auto cnt_f = get<2>(t);
        cnt_people += cnt_p;
        cnt_fuel += cnt_f + cnt_c;
    }
    return make_tuple(cnt_people, (cnt_people + 4) / 5, cnt_fuel);
}

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int n = A.size();
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n; ++i) {
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }
    return get<2>(dfs(0, -1, g));
}


int main(int argc, char const *argv[])
{
    vector<int> a{1, 1, 1, 9, 9, 9, 9, 7, 8};
    vector<int> b{2, 0, 3, 1, 6, 5, 4, 0, 0};
    cout << solution(a, b) << endl;
    return 0;
}
