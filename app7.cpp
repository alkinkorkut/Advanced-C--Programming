#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

// Defines a type alias. Here is used to simplify the syntax for declaring
// function pointers that take two integer parameters and return an integer.
using TwoInters = int (*)(int, int);

// Take one integer as a parameter and return an integer
using OneInter = int (*)(int);

int dosmt1(int a) { return a; }
int dosmt2(int a) { return a*a; }
int incrementBy1(int a) { return a+1; }

int incrementByK_K;
int incrementByK(int a) { return a + incrementByK_K; }

int incrementByKMulM_K;
int incrementByKMulM_M;
int incrementByKMulM(int a) {
    return (a + incrementByKMulM_K) * incrementByKMulM_M;
}

// "decltype" is used to determine the type of an expression at compile time.
void transform(vector<int>& v, OneInter funcptr) {
    auto sz = v.size();
    for(decltype(sz) i = 0; i < sz; i++)
        v[i] = funcptr(v[i]);
}

int main(int argc, char* argv[]) {

    return 0;
}