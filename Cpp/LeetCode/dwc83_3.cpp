#include "usual.h"

class NumberContainers {
    map<int, int> idx2num;
    map<int, set<int>> num2idx;

public:
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if (idx2num.count(index)) {
            int num = idx2num[index];
            num2idx[num].erase(index);
        }
        idx2num[index] = number;
        num2idx[number].insert(index);
    }
    
    int find(int number) {
        if (!num2idx.count(number) || num2idx[number].empty()) {
            return -1;
        }
        return *num2idx[number].begin();
    }
};

int main(int argc, char const *argv[])
{
    auto p = new NumberContainers();
    cout << p->find(10) << endl;
    p->change(2, 10);
    p->change(1, 10);
    p->change(3, 10);
    p->change(5, 10);
    cout << p->find(10) << endl;
    p->change(1, 20);
    cout << p->find(10) << endl;
    return 0;
}
