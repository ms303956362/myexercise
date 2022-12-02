#include "usual.h"

int solution(vector<int> &A) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    priority_queue<double> q;
    double total = 0;
    for (const auto& num : A) {
        total += num;
        q.push(num);
    }
    double sum = total;
    int ans = 0;
    while (sum > total / 2) {
        double num = q.top();
        q.pop();
        sum -= num / 2.0;
        q.push(num / 2.0);
        ++ans;
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    vector<int> A{3, 0, 5};
    cout << solution(A) << endl;
    return 0;
}
