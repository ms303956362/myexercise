#include <cstdio>
#include "List.h"
List<char> l;

char move(char dir_p, Posi<char> p) {

    return 'T';
}

char insert(Posi<char> p, char ch) {
    l.insertB(p, ch);
    return 'T';
}

char del(Posi<char> p) {
    if (l.valid(p)) {
        l.remove(p);
        return 'T';
    } else
        return 'F';
}

char rev(Posi<char> pl, Posi<char> pr) {
    // l.reverse(pl, pr->pred);
    return 'T';
}

void show() {

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

    // 操作
    int n;
    char op[2], arg0[2], arg1[2], res;
    Posi<char> pl = l.first(), pr = l.last()->succ;
    scanf("%d", &n);
    for (int i = 0; i != n; ++i) {
        scanf("%s", op);
        switch (op[0])
        {
        case '>':
            scanf("%s", arg0);
            res = move('l', (arg0[0] == 'L' ? pl : pr));
            printf("%c\n", res);
            break;

        case '<':
            scanf("%s", arg0);
            res = move('r', (arg0[0] == 'L' ? pl : pr));
            printf("%c\n", res);
            break;

        case 'I':
            scanf("%s %s", arg0, arg1);
            res = insert((arg0[0] == 'L' ? pl : pr), arg1[0]);
            printf("%c\n", res);
            break;

        case 'D':
            scanf("%s", arg0);
            res = del( (arg0[0] == 'L' ? pl : pr));
            printf("%c\n", res);
            break;

        case 'R':
            rev(pl, pr);
            printf("%c\n", res);
            break;
        
        case 'S':
            show();
            break;

        default:
            break;
        }
    }
    return 0;
}
