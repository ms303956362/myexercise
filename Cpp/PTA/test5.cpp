#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int k;
    scanf("%d", &k);
    vector<int> idx(54);
    for (int i = 0; i < 54; ++i) {
        scanf("%d", &idx[i]);
        --idx[i];
    }
    vector<string> v1, v2(54);
    string vc("SHCD");
    for (const auto& c : vc) {
        for (int i = 1; i <= 13; ++i) {
            v1.push_back(string(1, c) + to_string(i));
        }
    }
    v1.push_back("J1");
    v1.push_back("J2");
    for (int i = 0; i < k; ++i) {
        for (int i = 0; i < 54; ++i)
            v2[idx[i]] = v1[i];
        v1 = v2;
    }
    for (int i = 0; i < 54; ++i) {
        if (i > 0)
            printf(" ");
        printf("%s", v1[i].c_str());
    }
    return 0;
}
