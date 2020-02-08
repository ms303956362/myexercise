#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <memory>
using std::allocator;
using std::uninitialized_copy;

#include <utility>
using std::pair;

#include <cstring>
using std::strcmp;
using std::strlen;

class my_String {
    friend ostream &operator<<(ostream &os, my_String &mstr);
    friend bool operator==(const my_String &lms, const my_String &rms);
    friend bool operator!=(const my_String &lms, const my_String &rms);

private:
    static allocator<char> alloc;
    char *elements;
    char *first_free;
    char *cap;
    pair<char*, char*> alloc_n_copy(const char *b, const char *e);
    void free();
    void reallocate(size_t new_capacity);

public:
    my_String(const char *pc = "");
    my_String(const my_String &rs);
    my_String(my_String &&rs) noexcept;
    ~my_String();
    my_String& operator=(const my_String &rs);
    my_String& operator=(my_String &&rs) noexcept;
    size_t capacity() const { return cap - elements; }
    size_t size() const { return first_free - elements; }
    char *begin() { return elements; }
    char *end() { return first_free; }
    const char *begin() const { return elements; }
    const char *end() const { return first_free; }
};

allocator<char> my_String::alloc;

pair<char*, char*> my_String::alloc_n_copy(const char *b, const char *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void my_String::free() {
    if (elements){
        while(first_free != elements)
            alloc.destroy(--first_free);
        alloc.deallocate(elements, cap - elements);
    }
}

void my_String::reallocate(size_t new_capacity){
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

my_String::my_String(const char *pc) {
    auto sz = strlen(pc) + 1;
    auto new_data = alloc_n_copy(pc, pc + sz);
    elements = new_data.first;
    first_free = cap = new_data.second;
}

my_String::my_String(const my_String &rs){
    auto new_data = alloc_n_copy(rs.begin(), rs.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
    cout << "copy constructor" << endl;
}

my_String::my_String(my_String &&rs) noexcept : elements(rs.elements), first_free(rs.first_free), cap(rs.cap) {
    rs.elements = rs.first_free = rs.cap = nullptr;
    cout << "move constructor" << endl;
}

my_String::~my_String() {
    free();
}

my_String& my_String::operator=(const my_String &rs){
    auto new_data = alloc_n_copy(rs.begin(), rs.end());
    free();
    elements = new_data.first;
    first_free = cap = new_data.second;
    cout << "copy assignment" << endl;
    return *this;
}

my_String& my_String::operator=(my_String &&rs) noexcept {
    if (this != &rs){
        free();
        elements = rs.elements;
        first_free = rs.first_free;
        cap = rs.cap;
        rs.elements = rs.first_free = rs.cap = nullptr;
    }
    return *this;
}

ostream &operator<<(ostream &os, my_String &mstr) {
    os << mstr.elements;
    return os;
}

bool operator==(const my_String &lms, const my_String &rms){
    return strcmp(lms.elements, rms.elements);
}

bool operator!=(const my_String &lms, const my_String &rms){
    return strcmp(lms.elements, rms.elements);
}
