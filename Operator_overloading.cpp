#include <iostream>
#include <string>

struct COUT {
    std::string name;
    void operator<<(int value) {

        auto& self = *this;
        self.name = "NAME"; // "NAME" is of type const char[5]
        // left-side = string
        // right-side = const char[5]
        // in between there is operator= | operator=(self.name, "NAME");

        std::cout << value;
    }

    void operator() () {
        std::cout << "Hello!" << std::endl;
    }
};

COUT console;

int main(int argc, char* argv[] ) {
    std::cout  << 10 << std::endl;
    // operator<<(std::cout, 10);
    std::cout << "-----" << std::endl;

    console << 10;
    std::cout << std::endl;
    std::cout << console.name << std::endl;

    std::cout << "-----" << std::endl;
    console.operator<<(25);
    std::cout << std::endl;

    std::cout << "-----" << std::endl;
    console();
    console.operator()();

    return 0 ;
}