#include <iostream>
#include <vector> // an array dynamically allocated contiguously in heap memory
#include <list> // this is a linked-list implementation
#include <string>

using namespace std;

struct FibonacciGenerator {
    int a;
    int b;

    FibonacciGenerator(int& a, int& b) : a(a), b(b) { }

    int operator() (){
        auto retval = a + b;
        a = b;
        b = retval;
        return retval;
    };

};

int main(int argc, char* argv[]) {
    int a = 0;
    int b = 1;

    auto fg = FibonacciGenerator(a, b);
    cout << fg.a << endl;
    cout << fg.b << endl;

    cout << "-----" << endl;

    auto fg_lambda = [a, b]() mutable {
        auto retval = a + b;
        a = b;
        b = retval;
        return retval;
    };

    for(int i = 0; i < 10; i++)
        cout << fg_lambda() << endl;

    cout << "-----" << endl;
    cout << a << endl;
    cout << b << endl;

    return 0;
}