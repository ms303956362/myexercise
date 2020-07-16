#include "usual.h"

struct Node {
    int u;
    double p;
    Node(int v, double pp) : u(v), p(pp){}
};

bool operator<(const Node &n1, const Node &n2) { return n1.p < n2.p; }

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<int>> e(n, vector<int>());
        vector<vector<double>> p(n, vector<double>());
        vector<double> ans(n, 0);
        vector<int> vst(n, 0);
        for (int i = 0; i != edges.size(); ++i) {
            e[edges[i][0]].push_back(edges[i][1]);
            e[edges[i][1]].push_back(edges[i][0]);
            p[edges[i][0]].push_back(succProb[i]);
            p[edges[i][1]].push_back(succProb[i]);
        }
        // for (int i = 0; i != edges.size(); ++i) {
        //     p[edges[i][0]][edges[i][1]] = succProb[i];
        //     p[edges[i][1]][edges[i][0]] = succProb[i];
        // }
        dfs(start, n, e, p, vst, ans);
        return ans[end];
    }

    void dfs(int s, int n, vector<vector<int>>& e, vector<vector<double>> p, vector<int>& vst, vector<double>& ans) {
        priority_queue<Node> q;
        ans[s] = 1;
        q.push(Node(s, 1));
        while (!q.empty()) {
            Node node = q.top();
            q.pop();
            int u = node.u;
            double pu = node.p;
            if (vst[u] || ans[u] != pu)
                continue;
            vst[u] = 1;
            for (int i = 0; i != e[u].size(); ++i)
            {
                int v = e[u][i];
                if (ans[v] < ans[u] * p[u][i]) {
                    ans[v] = ans[u] * p[u][i];
                    if (!vst[v])
                        q.push(Node(v, ans[v]));
                }
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    int n = 3, s = 0, ed = 2;
    vector<vector<int>> e{{0, 1}};
    vector<double> p{0.5};
    cout << Solution().maxProbability(n, e, p, s, ed) << endl;
    return 0;
}
