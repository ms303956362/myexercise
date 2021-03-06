#include <cstdio>
#include "List.h"
List<char> l;
Posi<char> pl, pr; // 光标在指向元素的左侧间隙，范围[first(), trailer]
                   // 插入等价于insertB(p, e)，删除等价于remove(p)
int rl, rr; // 左右光标的rank

char move(char dir_p, Posi<char>& p) {
    char res = 'T';
    int& rp = (&p == &pl ? rl : rr);
    if (dir_p == 'l') { // 向左移动
        if (p == l.first()) // 到头
            res = 'F';
        else{
            p = p->pred;
            --rp;
        }
    } else {    // 向右移动
        if (p == l.last()->succ) // 到头
            res = 'F';
        else {
            p = p->succ;
            ++rp;
        }
    }
    return res;
}

char insert(Posi<char>& p, char ch) {
    l.insertB(p, ch);
    int &rp = (&p == &pl ? rl : rr), &r_another = (&p == &pl ? rr : rl);
    if (r_another >= rp)   // 未操作光标在操作光标右侧
        ++r_another;
    ++rp;
    return 'T';
}

char del(Posi<char>& p) {
    char res = 'T';
    int &rp = (&p == &pl ? rl : rr), &r_another = (&p == &pl ? rr : rl);
    Posi<char> &p_another = (&p == &pl ? pr : pl);
    if (l.valid(p)) { // 光标不在trailer
        bool eq = (p == p_another); // 两光标是否重合
        Posi<char> succ = p->succ;
        l.remove(p);
        p = succ;
        if (eq)
            p_another = p;  // 重合时另一个光标也被删除，重新赋值
        if (r_another > rp)
            --r_another;
    } else { // 光标不在trailer
        res = 'F';
    }
    return res;
}

char rev(Posi<char>& pl, Posi<char>& pr) {
    char res;
    if (rr - rl >= 1){
        l.reverse(pl, pr->pred);
        res = 'T';
    } else {
        res = 'F';
    }
    return res;
}

void show() {
    for (Posi<char> p = l.first(); p != l.last()->succ; p = p->succ) {
        printf("%c", p->data);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);

    // 读取初始序列
    char *s = new char[3200003];
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; ++i) {
        l.insertAsLast(s[i]);
    }
    delete[] s;
    rl = 0;
    rr = l.size();
    pl = l.first();
    pr = l.last()->succ;

    // 操作
    int n;
    char op[2], arg0[2], arg1[2], res='T';
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        scanf("%s", op);
        switch (op[0]) {
        case '>':
            scanf("%s", arg0);
            res = move('r', (arg0[0] == 'L' ? pl : pr));
            break;

        case '<':
            scanf("%s", arg0);
            res = move('l', (arg0[0] == 'L' ? pl : pr));
            break;

        case 'I':
            scanf("%s %s", arg0, arg1);
            res = insert((arg0[0] == 'L' ? pl : pr), arg1[0]);
            break;

        case 'D':
            scanf("%s", arg0);
            res = del( (arg0[0] == 'L' ? pl : pr));
            break;

        case 'R':
            res = rev(pl, pr);
            break;
        
        case 'S':
            show();
            break;

        default:
            break;
        }
        if( op[0] != 'S')
            printf("%c\n", res);
    }
    return 0;
}
