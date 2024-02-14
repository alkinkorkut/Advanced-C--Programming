#include <iostream>
#include <vector>

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
/*
void transform(vector<int>& v, OneInter funcptr) {
    auto sz = v.size();
    for(decltype(sz) i = 0; i < sz; i++)
        v[i] = funcptr(v[i]);
}
 */

/*
template<typename Container, typename Func>
void transform(Container& v, Func funcptr) {
    for(auto iter = v.begin(); iter != v.end; iter++) {
        auto& item = *iter;
        item = funcptr(item);
    }
}
*/

template<typename Container, typename Object>
void transform(Container& v, const Object& obj) {
    for (auto& item : v) {
        /*
        for(auto iter = v.begin(); iter != v.end(); iter++) {
            auto& item = *iter;
            item = obj.run(item);
        }
         */
        item = obj(item);
    }
}

/*
template<typename Container, typename Func>
void transform(Container& v, Func funcptr, int k) {
    for(auto iter = v.begin(); iter != v.end(); iter++) {
        auto &item = *iter;
        item = funcptr(item, k);
    }
};
*/

template<typename Container>
void print(const Container& v) {
    for(auto iter = v.begin(); iter != v.end(); iter++) {
        const auto& item = *iter;
        cout << item << ' ';
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    auto v = vector<int>();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(10);
    v.push_back(20);
    print(v);

    incrementByKMulM_K = 10;
    incrementByKMulM_M = 2;
    transform(v, &incrementByKMulM);
    print(v);

    struct IncrementByKMulM {
        int K;
        int M;

        IncrementByKMulM(int K, int M) : K(K), M(M) { }

        inline int operator() (int a) const {
            return (a + K) * M;
        }
    };

    auto obj = IncrementByKMulM(5, 100);

    transform(v, [K=5, M=100](int a) { return (a+K) * M; });
    print(v);

    return 0;
}