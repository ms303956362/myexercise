#include "usual.h"

class MinStack {
private:
    stack<int> s;
    multiset<int> t;
    int min_elem;

public:
    /** initialize your data structure here. */
    MinStack() : min_elem(INT_MAX) {
        
    }
    
    void push(int x) {
        s.push(x);
        t.insert(x);
        if (x < min_elem)
            min_elem = x;
    }
    
    void pop() {
        int x = s.top();
        s.pop();
        t.erase(t.find(x));
        min_elem = *t.begin();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_elem;
    }
};

int main(int argc, char const *argv[])
{
    MinStack m;
    m.push(2147483646);
    m.push(2147483646);
    m.push(2147483647);
    cout << m.top() << endl;
    m.pop();
    cout << m.getMin() << endl;
    m.pop();
    cout << m.getMin() << endl;
    m.pop();
    m.push(2147483647);
    cout << m.top() << endl;
    cout << m.getMin() << endl;
    m.push(-2147483648);
    
    return 0;
}
