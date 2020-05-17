#include <cstdio>
#include <cstring>
#include "PQ1.h"

struct Process
{
    int id;
    int prio;
    int start;
    int etime;
    long long last;
};

bool operator<(const Process &lp, const Process &rp) { return lp.prio < rp.prio || (lp.prio == rp.prio && lp.start > rp.start) || (lp.prio == rp.prio && lp.start == rp.start && lp.id > rp.id); }

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    PQ_ComplHeap<Process> q;
    int n, cnt = 1;
    scanf("%d", &n);
    long long time;
    Process p;
    scanf("%d %d %d %d", &p.id, &p.prio, &p.start, &p.etime);
    p.last = p.start;
    q.insert(p);
    bool first = true;
    while (!q.empty()) {
        long long top_time = q.getMax().last + (long long)q.getMax().etime;
        if(cnt == n)  // 更新时间
            time = top_time;
        else
            time = (p.start < top_time ? p.start : top_time);
        if (time >= top_time) { // 堆顶进程已完成
            printf("%d %lld\n", q.getMax().id, top_time);
            q.delMax();
            if (!q.empty())
                q.getMax().last = time;
        }
        if (cnt < n && time >= p.start) {    // 创建新进程
            if (p.prio > q.getMax().prio) {    // 抢占
                q.getMax().etime -= time - q.getMax().last;   // 剩余执行时间
                p.last = time;
            }
            if (!first) {
                q.insert(p);
                ++cnt;
            }
            else
                first = false;
            while (cnt < n) {
                scanf("%d %d %d %d", &p.id, & p.prio, &p.start, &p.etime);
                if (p.start > time)
                    break;
                if (p.prio > q.getMax().prio) {    // 抢占
                    q.getMax().etime -= time - q.getMax().last;   // 剩余执行时间
                    p.last = time;
                }
                q.insert(p);
                ++cnt;
            }
        }
    }
    return 0;
}

