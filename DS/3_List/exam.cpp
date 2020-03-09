#include <cstdio>
#include "List.h"

int main(int argc, char const *argv[])
{
    List<int> l;
    int n, m;
    scanf("%d %d", &n, &m);

    int id;
    int step;
    Posi<int> p_curr = nullptr;
    for (int i = 0; i != n;++i) {
        scanf("%d", &id);
        if (i == 0) {
            p_curr = l.insertAsFirst(id);
        } else {
            step = m % i - 1; // 走过人数，上一人第1人所以减1
            while(step != 0) {
                if (step < 0) {
                    if (l.valid(p_curr->pred))
                        p_curr = p_curr->pred;
                    else
                        p_curr = l.last();
                    ++step;
                }
                else{
                    if (l.valid(p_curr->succ))
                        p_curr = p_curr->succ;
                    else
                        p_curr = l.first();
                    --step;
                }
            }
            p_curr = l.insertA(p_curr, id);
        }
    }
    // 输出
    for (int i = 0; i != l.size(); ++i) {
        if (i == 0)
            printf("%d", p_curr->data);
        else
            printf(" %d", p_curr->data);
        if (!l.valid(p_curr->pred))
            p_curr = l.last();
        else
            p_curr = p_curr->pred;
    }
    return 0;
}
