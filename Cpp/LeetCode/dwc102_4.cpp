#include "usual.h"

class Graph {
    int n;
    vector<vector<pair<int, int>>> g;
public:
    Graph(int _n, vector<vector<int>>& edges): n(_n), g(n) {
        for (const auto& e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
        }
        // for (const auto& e : edges) {
        //     dp[e[0]][e[1]] = e[2];
        // }
        // for (int u = 0; u < n; ++u) {
        //     dp[u][u] = 0;
        // }
        // for (int k = 0; k < n; ++k) {
        //     for (int i = 0; i < n; ++i) {
        //         for (int j = 0; j < n; ++j) {
        //             dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        //         }
        //     }
        // }
    }
    
    void addEdge(vector<int> edge) {
        g[edge[0]].emplace_back(edge[1], edge[2]);
        // int u = edge[0], v = edge[1], c = edge[2];
        // dp[u][v] = c;
        // for (int i = 0; i < n; ++i) {
        //     dp[u][i] = min(dp[u][i], c + dp[v][i]);
        //     dp[i][v] = min(dp[i][v], dp[i][u] + c);
        // }
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         dp[i][j] = min({dp[i][j], dp[i][u] + dp[u][j], dp[i][v] + dp[v][j]});
        //     }
        // }
    }
    
    int shortestPath(int node1, int node2) {
        // return dp[node1][node2] >= 0x3f3f3f3f ? -1 : dp[node1][node2];
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(0, node1);
        vector<int> dis(n, 0x3f3f3f3f);
        dis[node1] = 0;
        while (!q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            if (u == node2) {
                return dis[u];
            }
            if (d > dis[u]) {
                continue;
            }
            for (const auto& [v, c] : g[u]) {
                if (dis[u] + c < dis[v]) {
                    dis[v] = dis[u] + c;
                    q.emplace(dis[v], v);
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}

/**

["Graph","addEdge","addEdge","addEdge","addEdge","addEdge","shortestPath","shortestPath","shortestPath","addEdge","addEdge","addEdge","shortestPath","addEdge","addEdge","shortestPath","shortestPath","shortestPath","addEdge","addEdge","shortestPath","shortestPath","shortestPath","shortestPath","addEdge","addEdge","shortestPath","shortestPath","shortestPath","shortestPath","shortestPath","addEdge","shortestPath","addEdge","shortestPath","shortestPath","shortestPath","addEdge","shortestPath","shortestPath","shortestPath","shortestPath","shortestPath","addEdge","shortestPath","shortestPath","shortestPath"]
[[13,[[11,6,84715],[7,9,764823],[6,0,315591],[1,4,909432],[6,5,514907],[9,6,105610],[3,10,471042],[7,10,348752],[5,11,715628],[6,1,973999],[8,7,593929],[7,6,64688],[6,4,741734],[10,1,894247],[9,7,81181],[2,11,75418],[12,2,85431],[7,2,260306],[11,9,640614],[2,3,648804],[4,12,568023],[0,8,730096],[9,11,633474],[3,6,390214],[1,10,117955],[9,8,222602],[10,7,689294]]],[[1,2,36450]],[[8,0,709628]],[[2,4,30185]],[[12,1,21696]],[[1,8,2553]],[8,9],[1,11],[3,4],[[4,6,2182]],[[7,5,206]],[[5,7,140]],[12,5],[[12,6,365184]],[[3,2,5]],[4,8],[7,10],[0,5],[[0,11,5]],[[1,7,5]],[0,8],[11,11],[7,4],[0,12],[[3,9,858944]],[[0,9,4]],[3,5],[4,5],[12,9],[9,8],[3,5],[[12,9,629052]],[3,8],[[4,0,545201]],[11,8],[4,11],[9,6],[[12,7,4]],[7,10],[2,5],[6,11],[12,2],[9,7],[[4,3,879736]],[1,3],[1,0],[4,6]]


[null,null,null,null,null,null,1358752,111868,1131948,null,null,null,632705,null,null,592272,348752,1324231,null,null,730096,400311,290491,1394477,null,null,557120,399164,433393,222602,557120,null,622462,null,622912,317778,105610,null,348752,557115,315596,85431,81181,null,685254,380284,402493]
[null,null,null,null,null,null,1358752,111868,1131948,null,null,null,605420,null,null,592272,348752,1324231,null,null,730096,0,290491,1394477,null,null,429354,399164,401984,222602,429354,null,570569,null,622912,317778,105610,null,348752,429349,315596,58146,81181,null,685254,380284,2182]

["Graph","addEdge","shortestPath","addEdge","shortestPath","addEdge","addEdge","addEdge","addEdge","addEdge","shortestPath","shortestPath","addEdge","shortestPath","shortestPath","shortestPath","addEdge","shortestPath","addEdge","addEdge","addEdge","addEdge","addEdge","shortestPath","shortestPath","shortestPath","shortestPath","addEdge","shortestPath","addEdge","shortestPath","addEdge","addEdge","shortestPath","addEdge","shortestPath","shortestPath","addEdge","shortestPath","shortestPath","addEdge","addEdge","shortestPath","addEdge","shortestPath","shortestPath","shortestPath","shortestPath","addEdge","shortestPath","addEdge","addEdge","shortestPath","shortestPath","shortestPath","shortestPath","addEdge","shortestPath","shortestPath","shortestPath","shortestPath","addEdge","addEdge","addEdge","addEdge","addEdge","shortestPath","shortestPath","shortestPath","shortestPath","shortestPath","addEdge","shortestPath","shortestPath","shortestPath","shortestPath","shortestPath","shortestPath","shortestPath","addEdge","shortestPath","shortestPath","addEdge"]
[[18,[[8,12,835881],[6,1,886222],[8,9,152139],[4,15,475979],[5,15,903985],[12,7,435256],[3,11,115877],[14,2,669007],[15,12,503987],[13,9,773256],[2,13,643974],[12,5,42565],[0,9,726934],[9,8,369110],[13,10,727485],[16,0,842868],[0,13,836101],[4,12,645669],[12,14,353649],[0,1,501402],[3,13,131383],[15,9,919433],[13,11,652190],[9,4,501551],[13,12,772479],[13,1,602418],[5,3,192091],[12,0,66326],[8,4,841136],[3,1,305879],[2,9,953806],[6,13,690575],[1,12,901363],[1,5,658225],[0,2,751532],[14,16,17590],[15,3,665278],[2,8,784019],[4,3,586413],[3,12,631462],[5,13,360949],[1,17,686861],[9,3,112100],[4,1,159862],[7,13,863940],[1,3,859524],[10,6,795021],[17,2,489450],[3,8,930965],[4,10,573998],[1,15,60334],[2,0,624060],[8,6,708518],[17,13,446713],[7,4,361258],[14,5,489098],[1,4,147944],[0,7,987717],[6,5,518191],[13,16,301057],[0,6,725177],[3,17,515457],[16,3,456018],[3,15,871393],[11,14,584427],[17,8,569473],[8,16,598786],[8,1,961881],[12,16,51206],[15,10,622641],[10,14,573146]]],[[9,2,775475]],[12,0],[[1,8,10688]],[16,16],[[7,10,194719]],[[6,15,10240]],[[4,8,7274]],[[5,1,5126]],[[14,12,230]],[3,11],[8,4],[[13,8,126]],[3,16],[13,3],[9,12],[[5,17,311469]],[7,0],[[11,2,659004]],[[12,3,470391]],[[11,5,112]],[[3,0,771142]],[[14,11,88]],[12,4],[17,17],[16,4],[15,8],[[9,6,176760]],[10,11],[[17,9,293661]],[10,13],[[9,12,54]],[[17,12,49]],[4,2],[[2,11,598588]],[5,17],[5,10],[[10,7,472952]],[0,15],[2,3],[[12,1,5]],[[9,16,147239]],[10,12],[[6,3,337163]],[10,7],[8,3],[17,10],[15,2],[[1,13,362779]],[3,14],[[8,17,112504]],[[16,2,2]],[13,17],[2,2],[15,12],[14,0],[[16,1,1]],[11,6],[0,9],[12,5],[0,15],[[3,5,1]],[[6,14,1]],[[13,15,1]],[[17,3,1]],[[8,2,1]],[5,1],[2,12],[7,8],[6,2],[12,5],[[7,0,962638]],[7,13],[13,12],[13,9],[6,13],[15,12],[0,16],[3,5],[[5,0,730643]],[9,16],[13,9],[[15,11,1]]]

[null,null,66326,null,0,null,null,null,null,null,115877,653690,null,432440,264365,743562,null,834421,null,null,null,null,null,195635,0,725077,562366,null,573234,null,896820,null,null,934888,null,311469,688101,null,561736,790791,null,null,573376,null,472952,264239,630024,1321845,null,637351,null,null,112630,0,503987,66556,null,344825,664229,42565,561736,null,null,null,null,null,5126,727067,368532,10925,42565,null,612420,112679,152265,254812,503987,675849,1,null,147239,152265,null]
[null,null,66326,null,0,null,null,null,null,null,115877,653690,null,432440,264365,743562,null,834421,null,null,null,null,null,195635,0,725077,562366,null,573234,null,896820,null,null,934888,null,311469,688101,null,561736,790791,null,null,573376,null,472952,264239,630024,1321845,null,637351,null,null,112630,0,503987,66556,null,344825,664229,42565,561736,null,null,null,null,null,5126,727067,368532,10925,42565,null,612420,112679,152265,254812,503987,675849,1,null,51260,152265,null]


*/