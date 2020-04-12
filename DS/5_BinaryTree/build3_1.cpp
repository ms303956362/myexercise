#include <cstdio>
#include <cstring>

class TreeNode {
public:
    int child;
    TreeNode *next;
    TreeNode(int c, TreeNode* n=nullptr) : child(c), next(n) {}
};

class Queue {
public:
    Queue(int n) : front(0), back(0), size(n) {
        q = new int[n];
    }

    void push(int x) {
        q[++back] = x;
    }

    int pop() {
        return q[++front];
    }

    bool empty() {
        return front == back;
    }

private:
    int front;
    int back;
    int size;
    int *q;
};

TreeNode* goAlongPath(TreeNode** tree, TreeNode*& x_pred) {
    int d, c;
    scanf("%d", &d);
    x_pred = tree[1];
    auto x = x_pred->next, p = x, p_pred = x_pred;
    int i, j;
    for (i = 0; i != d; ++i) {
        scanf("%d", &c);
        for (j = 0; j != c && x; ++j) {
            x_pred = x;
            x = x->next;
        }
        if (!x) {
            break;
        } else {
            p_pred = x_pred;
            p = x;
            x_pred = tree[x->child];
            x = x_pred->next;
        }
    }
    while (++i < d)
        scanf("%d", &c);
    x = p;
    x_pred = p_pred;
    return x;
}

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    int n, m;
    scanf("%d %d", &n, &m);
    TreeNode **tree = new TreeNode *[n + 1];
    for (int i = 1; i <= n; ++i) {
        int k, node;
        scanf("%d", &k);
        tree[i] = new TreeNode(-1); // header
        TreeNode *p = tree[i];
        for (int j = 0; j != k; ++j) {
            scanf("%d", &node);
            p->next = new TreeNode(node);
            p = p->next;
        }
    }
    for (int i = 0; i != m; ++i) {
        auto x_src_pred = tree[1], p_dst_pred = x_src_pred;
        // 删除
        auto x_src = goAlongPath(tree, x_src_pred);
        x_src_pred->next = x_src->next;
        // 增加
        auto p_dst = goAlongPath(tree, p_dst_pred);
        int r;
        scanf("%d", &r);
        auto x_dst_pred = tree[p_dst->child];
        for (int i = 0; i != r; ++i) {
            x_dst_pred = x_dst_pred->next;
        }
        x_src->next = x_dst_pred->next;
        x_dst_pred->next = x_src;
    }
    Queue q(n);
    q.push(1);
    while (!q.empty()) {
        int k = q.pop();
        printf("%d\n", k);
        auto p = tree[k]->next;
        while (p) {
            q.push(p->child);
            p = p->next;
        }
    }
    return 0;
}
