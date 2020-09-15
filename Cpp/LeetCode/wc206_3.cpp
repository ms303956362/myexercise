#include "usual.h"

class Solution {
    const int INF=0x3f3f3f3f;
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> cost(n, vector<int>(n, 0));
        vector<int> dis(n, 0);
        int *vis = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cost[i][j] = abs(points[i][0] - points[j][0]) + (points[i][1] - points[j][1]);
                cost[j][i] = cost[i][j];
            }
        }
        return Prim(n, cost, dis, vis);
    }

    int Prim(int n, vector<vector<int>>& cost, vector<int>& dis, int* vis){
        int ans=0;
        memset(vis,false,sizeof(vis));
        vis[0]=true;
        for(int i=1;i<n;i++){
            dis[i]=cost[0][i];
        }
        for(int i=1;i<n;i++){
            int Min=INF;
            int k=-1;
            for(int j=0;j<n;j++){
                if(!vis[j] && Min>dis[j]){
                    k=j;
                    Min=dis[j];
                }
            }
            if(k==-1){
                return -1;
            }
            ans+=Min;
            vis[k]=true;
            for(int j=0;j<n;j++){
                if(!vis[j] && dis[j]>cost[k][j]){
                    dis[j]=cost[k][j];
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
