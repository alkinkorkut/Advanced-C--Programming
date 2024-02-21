#include <iostream>

using namespace std;

struct Fraction {
    int n;
    int d;

    Fraction(int n, int d=1) : n(n), d(d) { }

    Fraction(const Fraction& other) : n(other.n), d(other.d) {
        cout << "copy constructor of Fraction called" << endl;
    }

    // copy-assignment operator
    void operator=(const Fraction& right) {
        this->n = right.n;
        this->d = right.d;
        cout << "copy assignment of Fraction called" << endl;
    }

    operator double() {
        return double(n) / d;
    }
};

void print(const Fraction& f) {
    cout << f.n << "/" << f.d << endl;
}

int doit(int a, int b) { return a; }
int doit(float a, float b) { return a+b; }
int doit(double a, int b) { return a-b; }

auto operator"" _frac(long double value) {
    return Fraction(int(value));
}

int main(int argc, char* argv[]) {
    auto f0 = 25.0_frac;
    cout << "f0: ";
    print(f0);

    auto f1 = Fraction(1, 4);
    cout << "f1: ";
    print(f1);

    auto f2 = Fraction(5);
    cout << "f2: ";
    print(f2);
    cout << "-----" << endl;

    auto text = std::string("hi there");
    auto text2 = "hi there"s;

    f1 = f2; // copy assignment
    // f1.operator=(f2);
    cout << "f1: ";
    print(f1);

    cout << "-----" << endl;

    f1 = 15;
    cout << "f1: ";
    print(f1);

    cout << "-----" << endl;

    //Fraction f3(f1);
    //Fraction f3 = f1;
    auto f3 = f1; // copy constructor

    cout << "-----" << endl;

    f3 = f1;

    cout << "-----" << endl;

    cout << Fraction(15,4) << endl;

    return 0;
}