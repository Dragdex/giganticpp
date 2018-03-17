#include <vector>
#include <iostream>
#include <chrono>
#include <cstdlib>

#include "higherorder.hh"

using namespace giganticpp;
using namespace std;

int main(int , char **) {
    
    vector<int> v1 = {  10,  11,  12,  13,  14,  15};  // a vector
    vector<int> v2 = {1000,1100,1200,1300,1400,1500};  // a vector

    auto start = chrono::steady_clock::now();

    for (auto i=0; i < 10000000; i++) {
        auto r1 = mapf([](int x, int y) { return x + y; }, v1, v2);
    }

    auto end = chrono::steady_clock::now();

    cout << "const loop " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;


    start = chrono::steady_clock::now();

    for (auto i=0; i < 10000000; i++) {
        vector<int> v1 = {  rand(),  rand(),  rand(),  rand(),  rand(),  rand()};  // a vector
        vector<int> v2 = {  rand(),  rand(),  rand(),  rand(),  rand(),  rand()};  // a vector

        auto r1 = mapf([](int x, int y) { return x + y; }, v1, v2);
    }

    end = chrono::steady_clock::now();

    cout << "random loop " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

    return 0;
}
