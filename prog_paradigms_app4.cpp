#include <iostream>
#include <vector>

using namespace std;

int doit1(int a, int b) { return a; }
int doit2(int a, int b) { return a+b; }
int doit3(int a, int b) { return a-b; }

//typedef int (*TwoInters)(int, int);
using TwoInters = int (*)(int, int);
using OneInter = int (*)(int);

int dosmt1(int a) { return a; }
int dosmt2(int a) { return a*a; }
int dosmt3(int a) { return a+1; }

template<typename T>
void for_each(vector<T>& v, OneInter funcptr) {
    auto sz = v.size();
    for(decltype(sz) i = 0; i<sz; i++) {
        v[i] = funcptr(v[i]);
    }
}

template<typename T>
void print(const vector<T>& v) {
    for(const auto& item : v){
        cout << item << endl;
    }
}

int main(int argc, char* argv[]) {
    int choice = 1;
    int retval;

    TwoInters func;

    vector<int> V(10);
    for(int i=0; i<10; i++)
        V[i] = i;

    for_each(V, &dosmt3);
    print(V);


//    if(choice == 1)
//        func = &doit1;
////        retval = doit1(10, 20);
//    else if (choice == 2)
//        func = &doit2;
////        retval = doit2(10, 20);
//    else if (choice == 3)
//        func = &doit3;
////        retval = doit3(10, 20);
//    retval = func(10, 20);


//    if(choice == 1)
//        retval = doit1(10, 20);
//    else if (choice == 2)
//        retval = doit2(10, 20);
//    else if (choice == 3)
//        retval = doit3(10, 20);


//    cout << retval << endl;



    return 0;
}