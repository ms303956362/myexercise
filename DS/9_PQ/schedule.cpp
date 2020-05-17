#include "PQ1.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>

struct Task {
    long long id;
    char name[9];
    Task() = default;
    Task(const Task& t) : id(t.id) {
        strcpy(name, t.name);
    }
    Task& operator=(const Task& t) {
        id = t.id;
        strcpy(name, t.name);
        return *this;
    }
};

bool operator<(const Task &lt, const Task &rt) { return lt.id > rt.id || (lt.id == rt.id && strcmp(lt.name, rt.name) > 0); }

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    Task *tl = new Task[n];
    for (int i = 0; i != n; ++i) {
        scanf("%lld %s", &tl[i].id, tl[i].name);
    }

    PQ_ComplHeap<Task> q(tl, n);
    for (int i = 0; i != m && q.size() > 0; ++i) {
        Task t = q.delMax();
        printf("%s\n", t.name);
        t.id *= 2;
        if (t.id < (1LL << 32))
            q.insert(t);
    }
    return 0;
}
