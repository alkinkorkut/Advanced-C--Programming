// Target: Write a HeapValue<T> class that uses heap memory for storage! with all constructors and destructors
#include <iostream>
using namespace std;

template <typename T> // assuming T does not have any modifiers (no ref, no refref)
struct HeapValue {
    T* ptr = nullptr;

    // new style c-tor accessible by curly brackets
    HeapValue(std::initializer_list<int> content) {
        cout << "new ctor is called with a size of " << content.size() << endl;
    }

    HeapValue(int) { // old style c-tor
        cout << "old ctor is called" << endl;
    }

    // default ctor: delegate construction to type T's default ctor: T{}
    HeapValue() : ptr(new T{}) { }

    // constructing HeapValue<T> from T types
    HeapValue(const T& t) : ptr(new T{t})  { }

    // copy c-tor of HeapValue<T>: clone the right hand side value by delegating to its own copy ctor
    HeapValue(const HeapValue<T>& other) : ptr(new T{*other.ptr}) { }

    // r-value ref binding to HeapValue<T>:
    // we use this kind of binding for signalling us that right side is a temporary value
    HeapValue(HeapValue<T>&& other)
            : ptr(other.ptr) // move the treasure of right side to yourself
    {
        other.ptr = nullptr; // then mark the right side's treasure pointer as null so that only owner is you
    }

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