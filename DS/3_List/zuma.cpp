#include <cstdio>
#include <iostream>
#include "List.h"

char s[20002];

Posi<char> insert(List<char>& l, int pos, char ch) {
    Posi<char> p = l.first();
    for (int j = 0; j != pos; ++j) {
        p = p->succ;
    }
    l.insertB(p, ch);
    return p->pred;
}

void printList(List<char>& l) {
    if (l.empty())
        printf("-\n");
    else {
        Posi<char> p = l.first();
        int i;
        for (i = 0; i != l.size(); ++i) {
            s[i] = p->data;
            p = p->succ;
        }
        s[i] = '\0';
        puts(s);
    }
}

int main(int argc, char const *argv[])
{
    List<char> l;
    char ch;
    int n, pos;

    ch = getchar();
    if (ch >= 'A' && ch <= 'Z') {
        s[0] = ch;
        scanf("%s", s + 1);
        for (int i = 0; s[i] >= 'A' && s[i] <= 'Z'; ++i) {
            l.insertAsLast(s[i]);
        }
    }
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        scanf("%d %c", &pos, &ch);
        Posi<char> p = insert(l, pos, ch);
        int cnt_l = 0, cnt_r = 0;
        // start check
        do {
            Posi<char> pl = p, pr = p;
            cnt_l = 0, cnt_r = 0;
            while (l.valid(pl->pred) && pl->pred->data == p->data) { // [pl, p)
                ++cnt_l;
                pl = pl->pred;
            }
            while (pr->data == p->data) { // [p, pr)
                ++cnt_r;
                pr = pr->succ;
            }
            if (cnt_r + cnt_l > 2) {
                while (pl != pr) {
                    l.remove(pl);
                    pl = pl->succ;
                }
            }
            p = l.valid(pr) ? pr : pr->pred;
        } while (!l.empty() && cnt_l + cnt_r > 2);
        // end check
        printList(l);
    }
    return 0;
}
