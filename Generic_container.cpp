// Write a Value<T> class that uses heap memory for storage! with all ctors and dtors
#include <iostream>

using namespace std;

template <typename T> // assuming T does not have any modifiers (no ref, no refref)
struct HeapValue {
    T* ptr = nullptr;

    // new style c-tor accessible by curly brackets
    HeapValue(std::initializer_list<T>content) {
        cout << "new constructor is called with a size of " << content.size() << endl;
    }

    // old style c-tor
    HeapValue(int) {
        cout << "old constructor is called" << endl;
    }

    // default constructor: delegate construction to type T's default constructor: T{}
    HeapValue() : ptr(new T{}) { }

    // constructing HeapValue<T> from T types
    HeapValue(const T& t) : ptr(new T{t}) { }

    // copy constructor of HeapValue<T>: clone the right hand side value by delegating to its own copy constructor
    HeapValue(const HeapValue<T>& other) : ptr(new T{*other.ptr}) { }

    // r-value ref binding to HeapValue<T>:
    // we use this kind of binding for signalling us that right side is a temporary value
    // will be implemented later on

    ~HeapValue() {
        delete ptr;
    }
};

int main(int argc, char* argv[]) {
    //auto h1 = new HeapValue<int>{};
    auto h1 = HeapValue<int>{};
    cout << *h1.ptr << endl;

    auto i = HeapValue<int>{};

    {
        auto j = HeapValue<int>{5};
    }

    auto t = HeapValue<string>{"Very Valuable and Big Treasure"};
    // HeapValue<string> t2(t); // old format
    auto t2 = t; // copy construction, t2 is being constructed
    // auto t3 = HeapValue<string>{"Very Valuable and Big Treasure"s}; // move from t2 (steal from t2), this indicates that t2 shall never be used again
    // auto t3 = (HeapValue<string>&&)t2; // move from t2 (steal from t2), this indicates that t2 shall never be used again

    cout << t2.ptr << endl;
    auto t3 = std::move(t2); // move construction, move from t2 (steal from t2), this indicates that t2 shall never be used again
    cout << t2.ptr << endl;
    cout << t3.ptr << endl;

    auto s4 = HeapValue<string>({1, 2, 3, 4, 10, 20});
    // auto v = std::vector<int>{10}; // size is 1 integer. that integer is 10
    // auto v2 = std::vector<int>(10); // size is 10 integers. all integers are default constructed

    return 0;
}