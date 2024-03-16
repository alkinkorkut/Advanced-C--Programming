#include <iostream>

// forward declaration of TypeDisplay, for compile time debugging purposes
template<typename T>
struct TypeDisplay;

using double_ref = double&;
using double_ref_ref = double&&;

void func (double_ref doubleRef) { }

// std::remove_reference<T>::type
template<typename A> struct RemoveReference { using type = A; };
template<typename B> struct RemoveReference<B&> { using type = B; };
template<typename C> struct RemoveReference<C&&> { using type = C; };

int main(int argc, char* argv[]) {
    // auto i = TypeDisplay<double>{};

    /*
        auto d1 = TypeDisplay<double_ref&>{}; // &
        auto d2 = TypeDisplay<double_ref&&>{}; // &
        auto d3 = TypeDisplay<double_ref_ref&>{}; // &
        auto d4 = TypeDisplay<double_ref_ref&&>{}; // &&
     */

    /*
        using D = std::remove_reference<double&>::type;
        auto d5 = TypeDisplay<D>{};

        using D2 = std::remove_reference<double&&>::type;
        auto d6 = TypeDisplay<D2>{};
     */


    return 0;
}