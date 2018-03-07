#include <vector>
#include <queue>
#include <array>
#include <string>
#include <iostream>

#include "higherorder.hh"

using namespace giganticpp;
using namespace std;

int main(int , char **) {

    vector<int> v1 = {  10,  11,  12,  13,  14,  15};  // a vector
    vector<int> v2 = {1000,1100,1200,1300,1400,1500};  // a vector

    auto v3 = mapf()([](int x, int y) -> int { return x + y; }, v1, v2);
    
    for (auto v : v3) {
        cout << v << ", ";
    }
    cout << endl;

    auto i1 = {1,2,3};  // a initializer list
    auto i2 = {10,20,30};  // a initializer list
    vector<int> v4 = {1000,1100,1200,1300,1400,1500};  // a vector

    // wow! we are mapping diferent types (vector and initializer list)
    auto i3 = mapf()([](auto x, auto y, auto z) { return x + y + z; }, i1, i2, v4);
    
    for (auto v : i3) {
        cout << v << ", ";
    }
    cout << endl;

    array<string, 3> s1 = {"a"s, "b"s, "c"s};
    queue<string> q1;
    q1.push("A"s);
    q1.push("B"s);
    q1.push("C"s);

  ///  auto a5 = mapf()([](auto x, auto y) { return x + y; }, s1, q1);



    return 0;
}
