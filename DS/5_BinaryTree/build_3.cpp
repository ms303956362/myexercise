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

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    int n;
    scanf("%d", &n);
    TreeNode **tree = new TreeNode *[n + 1];
    for (int i = 1; i <= n; ++i) {
        int k, node;
        scanf("%d", &k);
        TreeNode *p;
        tree[i] = nullptr;
        for (int j = 0; j != k; ++j) {
            scanf("%d", &node);
            if (!tree[i]) {
                tree[i] = new TreeNode(node);
                p = tree[i];
            } else {
                p->next = new TreeNode(node);
                p = p->next;
            }
        }
    }
    Queue q(n);
    q.push(1);
    while (!q.empty()) {
        int k = q.pop();
        printf("%d\n", k);
        auto p = tree[k];
        while (p) {
            q.push(p->child);
            p = p->next;
        }
    }
    return 0;
}
