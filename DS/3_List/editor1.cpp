#include <cstdio>
#include <cstring>
#include "List1.h"

List<char> l(3200000);
Pos pl, pr; // 光标在指向元素的左侧间隙，范围[first(), trailer]
                   // 插入等价于insertB(p, e)，删除等价于remove(p)
int rl, rr; // 左右光标的rank

void read(List<char>& l) {
    scanf("%s", l._elem);
    l._size = strlen(l._elem);
    // 处理哨兵节点
    l._prev[0] = l.header;
    l._succ[l._size - 1] = l.trailer;
    l._succ[l.header] = 0;
    l._prev[l.trailer] = l._size - 1;
    // 其他节点
    for (int i = 0; i != l._size; ++i) {
        if (i != 0)
            l._prev[i] = i - 1;
        if (i != l._size - 1)
            l._succ[i] = i + 1;
    }
    l.free = l._size;
}

char move(char dir_p, Pos& p) {
    char res = 'T';
    int& rp = (&p == &pl ? rl : rr);
    if (dir_p == 'l') { // 向左移动
        if (p == l.first()) // 到头
            res = 'F';
        else{
            p = l.prev(p);
            --rp;
        }
    } else {    // 向右移动
        if (p == l.succ(l.last())) // 到头
            res = 'F';
        else {
            p = l.succ(p);
            ++rp;
        }
    }
    return res;
}

char insert(Pos& p, char ch) {
    l.insertB(p, ch);
    int &rp = (&p == &pl ? rl : rr), &r_another = (&p == &pl ? rr : rl);
    if (r_another >= rp)   // 未操作光标在操作光标右侧
        ++r_another;
    ++rp;
    return 'T';
}

char del(Pos& p) {
    char res = 'T';
    int &rp = (&p == &pl ? rl : rr), &r_another = (&p == &pl ? rr : rl);
    Pos &p_another = (&p == &pl ? pr : pl);
    if (l.valid(p)) { // 光标不在trailer
        bool eq = (p == p_another); // 两光标是否重合
        Pos succ = l.succ(p);
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

char rev(Pos& pl, Pos& pr) {
    char res;
    if (rr - rl >= 1){
        l.reverse(pl, l.prev(pr));
        res = 'T';
    } else {
        res = 'F';
    }
    return res;
}

void show() {
    for (Pos p = l.first(); p != l.succ(l.last()); p = l.succ(p)) {
        printf("%c", l.elem(p));
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);

    // 读取初始序列
    read(l);
    rl = 0;
    rr = l.size();
    pl = l.first();
    pr = l.succ(l.last());

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
