
This shows Modern C++ can be used to program with same convenience as python.

See how easy is to work with Lambdas, Map, Reduce and Filter in Modern C++.

#######################################################################

Basic usage.

```cpp
vector<int> v1 = {  10,  11,  12,  13,  14,  15};  // a vector
vector<int> v2 = {1000,1100,1200,1300,1400,1500};  // a vector

auto r1 = mapf([](int x, int y) -> int { return x + y; }, v1, v2);

for (auto v : r1) {
    cout << v << ", ";
}
```

Prints

    1010, 1111, 1212, 1313, 1414, 1515,

#######################################################################

Now, let's use diffent types of containers. e.g. std::initializer_list and std::vector.
Also notice it is mapping 3 containers (in previous example it was 2)

```cpp
auto i1 = {1,2,3};  // a initializer list
auto i2 = {10,20,30};  // a initializer list
vector<int> v4 = {1000,1100,1200,1300,1400,1500};  // a vector

// wow! we are mapping diferent types (vector and initializer list)
auto r2 = mapf([](auto x, auto y, auto z) { return x + y + z; }, i1, i2, v4);

for (auto v : r2) {
    cout << v << ", ";
}
```

Prints

    1011, 1122, 1233,

#######################################################################

Now, containers are not only different, but they also carry different types of element. e.g. string and int

```cpp
// mix different types
array<string, 3> as1 = {"a"s, "b"s, "c"s};
deque<int> q1 = {1,2,3};

auto r3 = mapf([](auto x, auto y) { return x + to_string(y); }, as1, q1);

for (auto v : r3) {
    cout << v << ", ";
}
```

Prints

    a1, b2, c3,

#######################################################################

And finnally, let's use it directly for strings.

```cpp
string s1("edgard"s);
string s2("Lima"s);
string s3("gmail"s);

auto r4 = mapf<string, string>([](auto x, auto y, auto z) { return x <= y ? x <= z ? x : z : y <= z ? y : z; }, s1, s2, s3);

cout << r4 << endl;
```

Prints

    Ldaa
    
#######################################################################

The map, filter and reduce function do not come standardized in Modern C++.

The magic is done by few line of C++ template.
The source code for this magic is here [higherorder.hh](https://github.com/Dragdex/giganticpp/blob/master/comparing_python_cc/lambda_filter_map_reduce/higherorder.hh)

Of course you can copy/paste it and and use.
Disclaimer: It has been written for C++17, and may need adjustments for previous versions.
    
#######################################################################

To Do: implement Filter and Reduction

To Do: copy/paste python code for side-by-side comparison

To Do: performance comparison

To Do: conclusion

#######################################################################
