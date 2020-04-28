#include <cstdio>
#include "Hashtable.h"

struct String {
    char *s;
    String(const char *ss=""){
        s = new char[strlen(ss) + 1];
        strcpy(s, ss);
    }
    String(const String& ss) {
        s = new char[strlen(ss.s) + 1];
        strcpy(s, ss.s);
    }
    String& operator=(const String& ss) {
        delete[] s;
        s = new char[strlen(ss.s) + 1];
        strcpy(s, ss.s);
        return *this;
    }
    ~String() { delete[] s; s = nullptr;}
};

bool operator==(const String& s1, const String& s2) { return !strcmp(s1.s, s2.s); }
bool operator!=(const String& s1, const String& s2) { return strcmp(s1.s, s2.s); }
static size_t hashCode(const String& s) { return hashCode(s.s); }

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    int n;
    char s[10];
    HashTable<String, int> ht(20011);
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%s", s);
        int *p = ht.get(s);
        if (p) 
            ++*p;
        else
            ht.put(s, 1);
    }
    Entry<String, int> *p=nullptr;
    int max_cnt = 0;
    for (int i = 0; i != 20011; ++i) {
        p = ht.at(i);
        if (p && p->value > max_cnt) {
            strcpy(s, p->key.s);
            max_cnt = p->value;
        }
    }
    printf("%s %d", s, max_cnt);
    return 0;
}
