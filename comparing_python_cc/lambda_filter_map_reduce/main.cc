#include <vector>
#include <deque>
#include <array>
#include <string>
#include <iostream>

#include "higherorder.hh"

using namespace giganticpp;
using namespace std;

int main(int , char **) {

    vector<int> v1 = {  10,  11,  12,  13,  14,  15};  // a vector
    vector<int> v2 = {1000,1100,1200,1300,1400,1500};  // a vector

    auto r1 = mapf([](int x, int y) { return x + y; }, v1, v2);
    
    for (auto v : r1) {
        cout << v << ", ";
    }
    cout << endl;

    auto i1 = {1,2,3};  // a initializer list
    auto i2 = {10,20,30};  // a initializer list
    vector<int> v4 = {1000,1100,1200,1300,1400,1500};  // a vector

    // wow! we are mapping diferent types (vector and initializer list)
    auto r2 = mapf([](auto x, auto y, auto z) { return x + y + z; }, i1, i2, v4);
    
    for (auto v : r2) {
        cout << v << ", ";
    }
    cout << endl;

    // mix different types
    array<string, 3> as1 = {"a"s, "b"s, "c"s};
    deque<int> q1 = {1,2,3};

    auto r3 = mapf([](auto x, auto y) { return x + to_string(y); }, as1, q1);

    for (auto v : r3) {
        cout << v << ", ";
    }
    cout << endl;

    // map std::strings
    string s1("edgard"s);
    string s2("Lima"s);
    string s3("gmail"s);

    auto r4 = mapf<string, string>([](auto x, auto y, auto z) { return min(min(x,y),min(x,z)); }, s1, s2, s3);

    cout << r4 << endl;

    return 0;
}
