#include <iostream>

struct Vector3d {
    int a;
    int b;
    int c;

    // Default constructor
    Vector3d() : a(0), b(0), c(0) { }

    Vector3d(int a_, int b_, int c_) : a(a_), b(b_), c(c_) { }

    // This returns Vector3d
    auto operator+(const Vector3d& right) {
        Vector3d result;
        result.a = this->a + right.a;
        result.b = this->b + right.b;
        result.c = this->c + right.c;
        return result;
    }

};

// Returning type is void
auto print(const Vector3d& v) {
    std::cout << "a: " << v.a << " b: " << v.b << " c: " << v.c << std::endl;
}

int main(int argc, char* argv[]) {

    auto v1 = Vector3d();
    print(v1);

    auto v2 = Vector3d(1, 4, 6);
    print(v2);

    auto v3 = Vector3d(1, 8, 1);
    print(v3);

    auto v4 = v2 + v3;
    print(v4);


    return 0;
}