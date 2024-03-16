#include <iostream>
#include <string>

using namespace std;

// l-value -> left value
// r-value -> right value
// chain assignment

void func(int i) { } // l-value, this "i" is within the local scope of the function, this is a variable in the local scope, and l-value.
// it indicates that this "i" is going to be an integer, it will have a memory address. The value in the memory address is called as "i".

void func2(int&  i) { } // l-value reference, it can only bind to l-values. It can't bind to r-values. The value is an integer. It lives in
// a flat. It has a memory address. So, give me the memory address of the value. [the flat]

void func3(const int& i) { } // const l-value reference, it can bind to both l-values and r-values. Promise for read-only access.

void func4(const int&& i) { } // r-value reference, it can only bind to r-values. Promise for read-only access.
// Tell to the compiler, there is a temporary value, and I want to access it. I don't want to modify it. I want to read it.

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

    // l-value[function parameter] to l-value[call-side argument], (it clones the value)
    int i = 1;
    func(i);
    // --------

    // l-value[function parameter] to r-value[call-side argument][temporary value], (it clones the value)
    func(2);
    // --------

    // l-value reference[function parameter] to l-value[call-side argument], (it doesn't clone the value)
    int j = 3;
    func2(j);
    // --------

    // const l-value reference[function parameter] to l-value and r-value [call-side argument], (it doesn't clone the value)
    int k = 4;
    func3(k);
    func3(5);
    // --------

    // const r-value reference[function parameter] to r-value[call-side argument][temporary value], (it doesn't clone the value)
    func4(6);
    // --------


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
