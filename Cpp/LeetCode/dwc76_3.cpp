#include "usual.h"

class ATM {
    vector<int> cnt, money;

public:
    ATM(): cnt(5), money{20, 50, 100, 200, 500} {

    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) {
            cnt[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ret(5);
        for (int i = 4; i >= 0; --i) {
            ret[i] = min(amount / money[i], cnt[i]);
            amount -= ret[i] * money[i];
        }
        if (amount > 0) {
            return {-1};
        }
        for (int i = 0; i < 5; ++i) {
            cnt[i] -= ret[i];
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    ATM a;
    a.deposit({0, 10, 0, 3, 0});
    a.withdraw(500);
    return 0;
}
