#pragma once
#include "Bitmap.h"
#include "release.h"

template <typename K, typename V>
struct Entry { //词条模板类
   K key; V value; //关键码、数值
   Entry ( K k = K(), V v = V() ) : key ( k ), value ( v ) {}; //默认构造函数
   Entry ( Entry<K, V> const& e ) : key ( e.key ), value ( e.value ) {}; //基于克隆的构造函数
//    bool operator< ( Entry<K, V> const& e ) { return key <  e.key; }  //比较器：小于
//    bool operator> ( Entry<K, V> const& e ) { return key >  e.key; }  //比较器：大于
   bool operator== ( Entry<K, V> const& e ) { return key == e.key; } //判等器：等于
   bool operator!= ( Entry<K, V> const& e ) { return key != e.key; } //判等器：不等于
};

template<typename K, typename V>
class HashTable {  // 手动确定M，需要保证为素数，装填因子不负责最优
private:
    int N;
    int M;
    Entry<K, V> **ht;
    Bitmap *lzRemoval;

protected:
    bool isLzRemoved(int k) { return lzRemoval->test(k); }
    void lzRemove(int k) { lzRemoval->set(k); }
    int probe4Hit(const K &k);
    int probe4Free(const K &k);

public:
    HashTable(int m);
    ~HashTable();
    int size() const { return N; }
    bool put(const K& k, const V& v);
    V *get(const K& k);
    Entry<K, V> *at(int i) { return ht[i]; }
    bool remove(const K& k);
};

/*********************静态方法************************/
// static size_t hashCode(char c) { return static_cast<size_t>(c); }
// static size_t hashCode(int k) { return static_cast<size_t>(k); }
// static size_t hashCode(long long i) { return static_cast<size_t>((i >> 32) + static_cast<int>(i)); }
static long long hashCode(const char* s) {
    long long h = 0;
    int n = strlen(s);
    for (int i = 0; i != n; ++i) {
        h = (h << 5) | (h >> 27); // 循环左移5位
        h += static_cast<long long>(s[i]);
    }
    return h;
}

/*********************保护***************************/
template<typename K, typename V>
int HashTable<K, V>::probe4Hit(const K &k) { // 找匹配
    long long c = hashCode(k) % M, r = c;
    int i = 1;
    while ((ht[r] && ht[r]->key != k) || (!ht[r] && isLzRemoved(r))) {
        r = (c + i * i) % M;
        ++i;
    }
    return r;
}

template<typename K, typename V>
int HashTable<K, V>::probe4Free(const K &k) { // 找空桶
    long long c = hashCode(k) % M, r = c;
    int i = 1;
    while (ht[r]) {
        r = (c + i * i) % M;
        ++i;
    }
    return r;
}

/********************对外接口*************************/
template<typename K, typename V>
HashTable<K, V>::HashTable(int m) : N(0), M(m) {
    ht = new Entry<K, V>*[m];
    memset(ht, 0, sizeof(Entry<K, V> *) * m);
    lzRemoval = new Bitmap(M);
}

template<typename K, typename V>
HashTable<K, V>::~HashTable() {
    for (int i = 0; i != M; ++i) {
        if (ht[i])
            release(ht[i]);
    }
    release(ht);
    release(lzRemoval);
}

template<typename K, typename V>
bool HashTable<K, V>::put(const K& k, const V& v) {
    if (ht[probe4Hit(k)]) { // 相同元素直接返回
        return false;
    }
    int r = probe4Free(k);
    ht[r] = new Entry<K, V>(k, v);
    ++N;
    return true;
}

template<typename K, typename V>
V *HashTable<K, V>::get(const K& k) {
    int r = probe4Hit(k);
    return ht[r] ? &(ht[r]->value) : nullptr;
}

template<typename K, typename V>
bool HashTable<K, V>::remove(const K& k) {
    int r = probe4Hit(k);
    if (!ht[r])
        return false;
    lzRemove(r);
    release(ht[r]);
    ht[r] = nullptr;
    --N;
    return true;     
}
