#include <string>
using std::string;

#include <utility>
using std::pair;

#include <memory>
using std::allocator;
using std::uninitialized_copy;

#include <initializer_list>
using std::initializer_list;

#include <algorithm>
using std::for_each;

class My_StrVec
{
    friend bool operator==(const My_StrVec &lmsv, const My_StrVec &rmsv);
    friend bool operator!=(const My_StrVec &lmsv, const My_StrVec &rmsv);

private:
    using T = string;
    static allocator<T> alloc;
    T *elements;
    T *first_free;
    T *cap;
    void chk_n_alloc() { if(first_free == cap) reallocate(); }
    pair<T *, T *> alloc_n_copy(const T *b, const T *e);
    void free();
    void reallocate();

public:
    My_StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr){};
    My_StrVec(initializer_list<T> il);
    My_StrVec(const My_StrVec &rmsv);
    My_StrVec(My_StrVec &&rmsv) noexcept;
    ~My_StrVec();
    My_StrVec& operator=(const My_StrVec &rmsv);
    My_StrVec& operator=(My_StrVec &&rmsv) noexcept;
    T &at(size_t i) const { return *(elements + i); }
    void push_back(const T &elem);
    size_t capacity() const { return cap - elements; }
    void reserve(size_t new_capacity);
    size_t size() const { return first_free - elements; }
    void resize(size_t new_sz);
    T *begin() { return elements; }
    T *end() { return first_free; }
    const T *begin() const { return elements; }
    const T *end() const { return first_free; }
};

allocator<My_StrVec::T> My_StrVec::alloc;

pair<My_StrVec::T*, My_StrVec::T*> My_StrVec::alloc_n_copy(const My_StrVec::T *b, const My_StrVec::T *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void My_StrVec::free() {
    if (elements){
        // while(first_free != elements)
        //     alloc.destroy(--first_free);
        for_each(elements, first_free, [](const T &elem) { alloc.destroy(&elem); });
        alloc.deallocate(elements, cap - elements);
    }
}

void My_StrVec::reallocate(){
    auto new_capacity = (size() > 0 ? 2 * size() : 1);
    auto new_elem = alloc.allocate(new_capacity);
    auto dest = new_elem;
    auto elem = elements;
    while (elem != first_free)
    {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = new_elem;
    first_free = dest;
    cap = elements + new_capacity;
}

My_StrVec::My_StrVec(initializer_list<My_StrVec::T> il) {
    auto new_ptr = alloc_n_copy(il.begin(), il.end());
    elements = new_ptr.first;
    first_free = cap = new_ptr.second;
}

My_StrVec::My_StrVec(const My_StrVec& rmsv) {
    auto new_ptr = alloc_n_copy(rmsv.begin(), rmsv.end());
    elements = new_ptr.first;
    first_free = cap = new_ptr.second;
}

My_StrVec::My_StrVec(My_StrVec &&rmsv) noexcept : elements(rmsv.elements), first_free(rmsv.first_free), cap(rmsv.cap){
    rmsv.elements = rmsv.first_free = rmsv.cap = nullptr;
}

My_StrVec::~My_StrVec() {
    free();
}

My_StrVec& My_StrVec::operator=(const My_StrVec& rmsv) {
    auto new_ptr = alloc_n_copy(rmsv.begin(), rmsv.end());
    free();
    elements = new_ptr.first;
    first_free = cap = new_ptr.second;
    return *this;
}

My_StrVec& My_StrVec::operator=(My_StrVec &&rmsv) noexcept {
    if (this != &rmsv){
        free();
        elements = rmsv.elements;
        first_free = rmsv.first_free;
        cap = rmsv.cap;
        rmsv.elements = rmsv.first_free = rmsv.cap = nullptr;
    }
    return *this;
}

void My_StrVec::push_back(const My_StrVec::T& elem){
    chk_n_alloc();
    alloc.construct(first_free++, elem);
}

void My_StrVec::reserve(size_t new_capacity){
    if (new_capacity <= capacity())
        return;
    auto new_data = alloc.allocate(new_capacity);
    auto dest = new_data;
    auto elem = elements;
    while (elem != first_free)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

void My_StrVec::resize(size_t new_sz){
    if (new_sz > size()){
        if (capacity() < 2*new_sz)
            reserve(2 * new_sz);
        while (first_free != elements + new_sz)
            alloc.construct(first_free++);
    } else if (new_sz < size()) {
        while (first_free != elements + new_sz)
            alloc.destroy(--first_free);
    }
}

bool operator==(const My_StrVec &lmsv, const My_StrVec &rmsv){
    auto liter = lmsv.elements;
    auto riter = rmsv.elements;
    while (liter != lmsv.first_free && riter != rmsv.first_free){
        if (*liter++ != *riter++)
            break;
    }
    if (liter == lmsv.first_free && riter == rmsv.first_free)
        return true;
    else
        return false;
}

bool operator!=(const My_StrVec &lmsv, const My_StrVec &rmsv){
    return !(lmsv == rmsv);
}
