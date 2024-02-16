#include <iostream>

int i = 10;

struct Vector2d {
    int a;
    int b;

    Vector2d() : a(0), b(0) { }

    Vector2d(int a_, int b_) : a(a_), b(b_) { }

    Vector2d addVectors(const Vector2d& second) {
        Vector2d result;
        result.a = this->a + second.a;
        result.b = this->b + second.b;
        return result;
    }

    Vector2d operator+(const Vector2d& right) {
        Vector2d result;
        result.a = this->a + right.a;
        result.b = this->b + right.b;
        return result;
    }
};

//Vector2d operator+(const Vector2d& left, const Vector2d& right) {
//    Vector2d result;
//    result.a = left.a + right.a;
//    result.b = left.b + right.b;
//    return result;
//}

void func() {
    int i = 100;
    Vector2d A(5,7);
    Vector2d B(-1, 3);
    Vector2d C = A + B;
    std::cout << C.a << std::endl;
    std::cout << C.b << std::endl;

}
int main(int argc, char* argv[]) {
    func();
    return 0;
}