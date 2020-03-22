#include <cstdio>
#include <cstring>

void reconstruct(int* pre, int* post, int* in, int n) {
    if (n == 1) {   // n不可能为2，否则不是真二叉树
        in[0] = pre[0];
        return;
    }
    // n >= 3
    int idx_lr_post = 0, idx_rr_pre = n - 1;
    int n_l, n_r;
    // 查找后序遍历中左子树根元素、左子树元素个数
    while (post[idx_lr_post] != pre[1])
        ++idx_lr_post;
    n_l = idx_lr_post + 1;
    // 查找先序遍历中右子树根元素、右子树元素个数
    while (pre[idx_rr_pre] != post[n - 2])
        --idx_rr_pre;
    n_r = n - idx_rr_pre;
    // 确定中序遍历根元素
    in[n_l] = pre[0];
    // 重构左、右子树
    reconstruct(pre + 1, post, in, n_l);
    reconstruct(pre + idx_rr_pre, post + n_l, in + n_l + 1, n_r);
}

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    
    int n;
    scanf("%d", &n);
    int *pre = new int[n], *post = new int[n], *in = new int[n];
    for (int i = 0; i != n; ++i) {
        scanf("%d", pre + i);
    }
    for (int i = 0; i != n; ++i) {
        scanf("%d", post + i);
    }
    reconstruct(pre, post, in, n);
    for (int i = 0; i != n; ++i) {
        printf("%d ", in[i]);
    }
    return 0;
}
