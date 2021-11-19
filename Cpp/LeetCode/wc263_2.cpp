#include "usual.h"

class Bank {
    int n;
    vector<long long> b;

public:
    Bank(vector<long long>& balance): n(balance.size()), b(balance) {

    }
    
    bool transfer(int account1, int account2, long long money) {
        if (1 <= account1 && account1 <= n && 1 <= account2 && account2 <= n) {
            if (money <= b[account1 - 1]) {
                b[account1 - 1] -= money;
                b[account2 - 1] += money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (1 <= account && account <= n) {
            b[account - 1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if (1 <= account && account <= n && b[account - 1] >= money) {
            b[account - 1] += money;
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
