#include "usual.h"

class Solution {
public:
    bool hasCycle(string graph) {
        unordered_map<int, vector<int>> g;
        unordered_map<int, int> in;
        unordered_set<int> nodes;
        function<void(void)> build = [&](void)
        {
            int i = 0, n = graph.size();
            while (i < n) {
                int j = i;
                while (j < n && graph[j] != '-') {
                    ++j;
                }
                int k = j + 2;
                while (k < n && graph[k] != ',') {
                    ++k;
                }
                int u = stoi(graph.substr(i, j - i)), v = stoi(graph.substr(j + 2, k - (j + 2)));
                g[u].push_back(v);
                nodes.insert(u);
                nodes.insert(v);
                in[v] += 1;
                i = k + 1;
            }
        };
        build();
        queue<int> q;
        for (const auto& u : nodes) {
            if (in[u] == 0) {
                q.push(u);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            ++cnt;
            for (const auto& v : g[u]) {
                --in[v];
                if (in[v] == 0) {
                    q.push(v);
                }
            }
        }
        return cnt != nodes.size();
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
