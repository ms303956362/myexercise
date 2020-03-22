#include <cstdio>
#include <cstring>
#include "Queue.h"

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

void reconstruct1(int *pre, int *in, int *post, int n) {
    if (n == 0)
        return;
    if (n == 1) {
        post[0] = pre[0];
        return;
    }
    post[n - 1] = pre[0];
    int idx_root = 0;
    while (in[idx_root] != pre[0])
        ++idx_root;
    int n_l = idx_root, n_r = n - n_l - 1;
    reconstruct1(pre + 1, in, post, n_l);
    reconstruct1(pre + 1 + n_l, in + 1 + n_l, post + n_l, n_r);
}

void reconstruct2(int *in, int *post, int *pre, int n) {
    if (n == 0)
        return;
    if (n == 1)
        pre[0] = post[0];
    pre[0] = post[n - 1];
    int idx_root = 0;
    while (in[idx_root] != post[n - 1])
        ++idx_root;
    int n_l = idx_root, n_r = n - n_l - 1;
    reconstruct2(in, post, pre + 1, n_l);
    reconstruct2(in + n_l + 1, post + n_l, pre + n_l + 1, n_r);
}

struct travItem {
    int *pre;
    int *post;
    int n;
    travItem(int *pr, int *po, int num) : pre(pr), post(po), n(num){};
};
using travPtr = travItem*;

void reconstruct3(int *pre, int *post, int* level, int n) {
    Queue<travPtr> q;
    q.enqueue(new travItem(pre, post, n));
    travPtr x;
    while (!q.empty()) {
        x = q.dequeue();
        *level++ = (x->pre)[0];
        if (x->n > 1) {
            int idx_left_in_post = 0;
            while ((x->post)[idx_left_in_post] != (x->pre)[1])
                ++idx_left_in_post;
            q.enqueue(new travItem(x->pre + 1, x->post, idx_left_in_post + 1));
            if (idx_left_in_post != x->n - 2) {
                int idx_right_in_pre = x->n - 1;
                while ((x->pre)[idx_right_in_pre] != (x->post)[x->n - 2])
                    --idx_right_in_pre;
                q.enqueue(new travItem(x->pre + idx_right_in_pre, x->post + idx_left_in_post + 1, x->n - idx_right_in_pre));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    
    int n, k;
    scanf("%d %d", &n, &k);
    int *pre = new int[n], *post = new int[n], *in = new int[n];
    for (int i = 0; i != n; ++i) {
        scanf("%d", pre + i);
    }
    for (int i = 0; i != n; ++i) {
        scanf("%d", post + i);
    }
    if (k == 0) 
        reconstruct(pre, post, in, n);
    else if (k == 1)
        reconstruct1(pre, post, in, n);
    else if (k == 2)
        reconstruct2(pre, post, in, n);
    else
        reconstruct3(pre, post, in, n);
    for (int i = 0; i != n; ++i) {
        printf("%d ", in[i]);
    }
    return 0;
}
