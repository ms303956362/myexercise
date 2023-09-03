#include "usual.h"

class Solution {
public:
    int minimizedStringLength(string s) {
        set<char> st;
        for (const auto& c : s) {
            st.insert(c);
        }
        return st.size();
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
