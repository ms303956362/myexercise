#include <cstdio>

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
    int *s = new int[n + 1];
    int top = -1, k = -1;
    long long cnt = 0;
    int curr = 0, last = 0;
    for (int i = 0; i != m; ++i) {  // 从顶至下遍历行
        for (int j = 0; j != n + 1; ++j) {  // 从左到右遍历列
            while (top >=0 && land[i][s[top]] >= land[i][j]) {    // pop后的s记录前缀中比当前元素小的最近元素的下标
                --top;  // 栈顶下标对应的元素不小于当前元素，弹出
            }
            curr = j;   // 查找前缀中比当前元素小的起点
            k = top;    // land[i][s[top]] < lang[i][j]
            while (k >= 0) {    // 栈顶下标对应的元素小于当前元素
                last = curr;
                curr = s[k--];
                if (j - curr < n_max){
                    cnt += land[i][last] * (last - curr);
                } else {
                    cnt += land[i][last] * (last + n_max - j);
                    break;
                }
            }
            s[++top] = j;
        }
        top = -1;
        k = -1;
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
