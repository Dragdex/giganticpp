#include <vector>
#include <iostream>

#include "higherorder.hh"

using namespace giganticpp;
using namespace std;

int main(int , char **) {
    
    auto v1 = {  10,  11,  12,  13,  14,  15};  // a vector
    auto v2 = {1000,1100,1200,1300,1400,1500};  // a vector

    auto r1 = mapf([](int x, int y) { return x + y; }, v1, v2);
    
    for (auto v : r1) {
        cout << v << ", ";
    }
    cout << endl;

    return 0;
}
