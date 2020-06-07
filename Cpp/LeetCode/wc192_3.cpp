#include "usual.h"

class BrowserHistory {
public:
    BrowserHistory(string homepage) : curr(0) {
        h.push_back(homepage);
    }
    
    void visit(string url) {
        while (h.size() - 1 > curr) {
            h.pop_back();
        }
        h.push_back(url);
        ++curr;
    }
    
    string back(int steps) {
        if (steps > curr)
            curr = 0;
        else
            curr -= steps;
        return h[curr];
    }
    
    string forward(int steps) {
        if (steps > (h.size() - 1 - curr))
            curr = h.size() - 1;
        else
            curr += steps;
        return h[curr];
    }

private:
    vector<string> h;
    int curr;
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
