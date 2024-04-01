// template parameter types: unknown typename, known typename with a value, auto in templates as a parameter

#include <iostream>
using namespace std;

template<typename T>
void func1(T t) { cout << "func1" << endl; }

template<typename T>
void func2() {
    if constexpr(is_integral_v<T>){
        cout << "func2, T is integral" << endl;
    }
    else {
        cout << "func2, T is not integral" << endl;
    }
}

template<typename T, T value>
void func3() {
    cout << "func3 value is "<< value << endl;
}

template<auto t>
void func4() {
    using T = decltype(t);
    cout << "func4 value is "<< t << endl;
}

int main(int argc, char* argv[]) {
    // void func1(T t) { cout << "func1" << endl; }
    func1(5);

    // void func2<float>() { cout << "func2, T is not integral" << endl; }
    func2<float>();

    // void func2<int>() { cout << "func2, T is integral" << endl; }
    func2<int>();

    // void func3<int, 10>() { cout << "func3 value is "<< value << endl; }
    func3<int, 10>();

    // void func4<5>() { cout << "func4 value is "<< t << endl; }
    func4<5>();

    return 0;
}