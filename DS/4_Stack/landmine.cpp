#include "Stack.h"
#include <cstdio>

void printLand(int **land, int n, int m) {
    for (int i = 0; i != m; ++i){
        for (int j = 0; j != n + 1; ++j)
            printf("%d ", land[i][j]);
        printf("\n");
    }
}

void createHist(int **land, int n, int m, int m_max) {
    for (int j = 1; j != n + 1; ++j) {
        for (int i = m - 2; i >= 0; --i ) {
            if (land[i][j] == 1) {
                if (land[i + 1][j] < m_max)
                    land[i][j] += land[i + 1][j];
                else
                    land[i][j] = land[i + 1][j];
            }
        }
    }
}

long long countMine(int **land, int n, int m, int n_max) {
    Stack<int> s, tmp;
    long long cnt = 0;
    int curr = 0, last = 0;
    for (int i = 0; i != m; ++i) {  // 从顶至下遍历行
        for (int j = 0; j != n + 1; ++j) {  // 从左到右遍历列
            curr = j;   // 查找前缀中比当前元素小的起点
            while (!s.empty()) {    // pop后的s记录前缀中比当前元素小的最近元素的下标
                if (land[i][s.top()] >= land[i][j]) { // 栈顶下标对应的元素不小于当前元素，弹出
                    s.pop();
                } else {    // 栈顶下标对应的元素小于当前元素
                    last = curr;
                    curr = s.top();
                    tmp.push(s.pop());
                    if (j - curr < n_max){
                        cnt += land[i][last] * (last - curr);
                    } else {
                        cnt += land[i][last] * (last + n_max - j);
                        break;
                    }
                }
            }
            while (!tmp.empty())
                s.push(tmp.pop());
            s.push(j);
        }
        while (!s.empty())
            s.pop();
    }
    return cnt;
}

int main(int argc, char const *argv[])
{
    int n, m, n_max, m_max;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &n_max, &m_max);
    int **land = new int*[m];
    for (int i = 0; i != m; ++i) {
        land[i] = new int[n + 1];
        land[i][0] = 0;
        for (int j = 1; j != n + 1; ++j) 
            scanf("%d", &land[i][j]);
    }
    createHist(land, n, m, m_max);
    long long cnt = countMine(land, n, m, n_max);
    printf("%d", cnt % 10007);
    return 0;
}
