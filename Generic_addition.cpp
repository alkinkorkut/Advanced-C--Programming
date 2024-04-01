// variadic templates, parameter packs, pack expansions (C++11 and later) "modern C++"
// - write an add function that adds all its input parameters

// fold expressions (C++17 and later) "more modern C++" ---> "modern C++"
// - write an add function that adds all its input parameters with fold expressions

// fold expressions and comma operator
// - write a print(...) function that prints all its input arguments to the console

#include <iostream>
using namespace std;

template <typename T1, typename T2>
auto addition1(T1 a, T2 b) { return a + b; }

template<auto a, auto b>
auto addition2() { return a + b; }

auto addition3() { return 0; }

template<typename First, typename ... Rest>
auto addition3(First first, Rest ... rest) {
    return first + addition3(rest...);
}

template<typename First, typename ... Rest>
inline auto addition4(First first, Rest ... rest) {
    if constexpr(sizeof...(rest) == 0){
        return first;
    }
    else {
        return first + addition4(rest...);
    }
}

template<typename ... Ts>
inline auto addition5(Ts ... ts) {
    return (ts + ...);
}

template<typename ... Ts>
auto print(Ts ... ts){
    ((cout << ts << ' '), ...);
}

int main(int argc, char* argv[]){
    cout << addition1(5, 6.7);
    cout << endl;
    cout << addition2<5, 6.9>();
    cout << endl;
    cout << addition3(5, 6.7, 8, 9.1);
    cout << endl;
    cout << addition4(5, 6.7, 8, 9.1);
    cout << endl;
    cout << addition5(1, 1.1, 2.2f, 35);
    cout << endl;

    print(1, 2.2, 3.3f, 4.4);
    return 0;
}