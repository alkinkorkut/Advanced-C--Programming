#include <iostream>
#include <string>

using namespace std;

// l-value -> left value
// r-value -> right value
// chain assignment

struct string_ {
    string_(const string&);
    string_(const char*);
};

int foo(string& str) { // can only bind to l values
    std::cout << str << std::endl;
    return 1;
}

int foo2(const string& str) { // const& situation -> can bind to both l&r values
                              // if const is removed, it can only bind to l values
    std::cout << str << std::endl;
    return 1;
}

int main(int argc, char* argv[]) {

    // int a = foo(string("hello world")); // This gives compiler error // bind to r-value
    // Right version of it
    string str_1 = string("hello world");
    int a = foo(str_1); // bind to l-value

    int b = foo2(string("hello world")); // bind to r-value

    int c = foo2("hi there"); // const char[9] -> const char*, bind to r-value

    int d = foo2(str_1); // bind to l-value

    // chain assignment (execute right to left)
    int e = 100;
    a = b = c = e = 5;
    a = b = c = e; // e is 5
    a = b = c; // c is 5 (c is assigned whatever e is [e's content is cloned to c])

    return 0;
}
