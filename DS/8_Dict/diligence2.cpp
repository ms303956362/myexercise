#include <cstdio>
#include <cstring>

char a[20011][10];
int cnt[20011];

struct Entry { //词条模板类
    char * key; 
    int value;
    Entry ( char* k, int v) : value ( v ) {
       key = new char[strlen(k) + 1];
       strcpy(key, k);
    }; 
    Entry (const Entry& e ) : value ( e.value ) {
       key = new char[strlen(e.key) + 1];
       strcpy(key, e.key);
    };
    ~Entry() {
       delete[] key;
       key = nullptr;
   }
};

class HashTable {  // 手动确定M，需要保证为素数，装填因子不负责最优
public:
    int N;
    int M;
    Entry **ht;

    int probe4Hit(char* k);
    int probe4Free(char* k);

    HashTable(int m);
    int size() const { return N; }
    bool put(char* k, int v);
    int *get(char* k);
};

/*********************静态方法************************/
static size_t hashCode(char* s) {
    int h = 0;
    size_t n = strlen(s);
    for (size_t i = 0; i != n; ++i) {
        h = (h << 5) | (h >> 27); // 循环左移5位
        h += static_cast<int>(s[i]);
    }
    return static_cast<size_t>(h);
}

/*********************保护***************************/
int HashTable::probe4Hit(char* k) { // 找匹配
    int c = hashCode(k) % M, r = c;
    int i = 1;
    while (ht[r] && strcmp(ht[r]->key, k)) {
        r = (c + i * i) % M;
        ++i;
    }
    return r;
}

int HashTable::probe4Free(char* k) { // 找空桶
    int c = hashCode(k) % M, r = c;
    int i = 1;
    while (ht[r]) {
        r = (c + i * i) % M;
        ++i;
    }
    return r;
}

/********************对外接口*************************/
HashTable::HashTable(int m) : N(0), M(m) {
    ht = new Entry*[m];
    memset(ht, 0, sizeof(Entry*) * m);
}

bool HashTable::put(char* k, int v) {
    if (ht[probe4Hit(k)]) { // 相同元素直接返回
        return false;
    }
    int r = probe4Free(k);
    ht[r] = new Entry(k, v);
    ++N;
    return true;
}

int *HashTable::get(char* k) {
    int r = probe4Hit(k);
    return ht[r] ? &(ht[r]->value) : nullptr;
}

int main(int argc, char const *argv[])
{
    setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);
    setvbuf(stdout, new char[1 << 20], _IOFBF, 1 << 20);
    int n;
    char s[10];
    HashTable ht(50087);
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%s", s);
        int *p = ht.get(s);
        if (p)
            ++*p;
        else
            ht.put(s, 1);
    }
    Entry *p=nullptr;
    int max_cnt = 0;
    for (int i = 0; i != 50087; ++i) {
        p = ht.ht[i];
        if (p && p->value > max_cnt) {
            strcpy(s, p->key);
            max_cnt = p->value;
        }
    }
    printf("%s %d", s, max_cnt);
    return 0;
}

