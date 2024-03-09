#include <iostream>

using namespace std;

// pointers
// constness -> east/west const

int main(int argc, char* argv[]) {

    auto pi_value = 3.14f;

    using float_pointer = float*;
    float_pointer float_ptr = &pi_value;

    cout << "The value of pi_value: " << pi_value << endl;
    cout << "The address of pi_value: " << float_ptr << endl;
    cout << "The value in the address of pi_value: " << *float_ptr << endl;
    cout << "------" << endl;

    auto gravity_value = 9.8f;
    float_ptr = &gravity_value;

    cout << "The value of gravity_value: " << gravity_value << endl;
    cout << "The address of gravity_value: " << float_ptr << endl;
    cout << "The value in the address of gravity_value: " << *float_ptr << endl;
    cout << "------" << endl;

    cout << sizeof(float) << " Bytes" << endl;
    cout << sizeof(float_ptr) << " Bytes" << endl;
    cout << "------" << endl;

    auto a_value = 10.0;
    auto b_value = 12.0;

    double * const double_ptr = &a_value;
    cout << "The address of a_value: " << double_ptr << endl;
    //double_ptr = &b_value; // this gives compiler error here
    cout << "The value in the address of a_value: " << *double_ptr << endl;
    cout << "------" << endl;

    double const * double_ptr2 = &b_value; // const double * double_ptr2 = &b_value;
    //*double_ptr2 = 125.0; // this gives compiler error here

    cout << sizeof(double) << " Bytes" << endl;
    cout << sizeof(double_ptr) << " Bytes" << endl;
    cout << "------" << endl;

    return 0;
}
