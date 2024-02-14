#include <iostream>
#include <vector>
#include <list>

using namespace std;

//template<typename Container, typename Func>
void transform_inline(auto& container, const auto& func) {
    for(auto& item: container) {
        item = func(item);
    }
}

auto transform(const auto& container, const auto& func) {
    auto new_container = container;
    for(auto& item : new_container) {
        item = func(item);
    }
    return new_container;
}

template<typename Container>
auto filter(const Container& container, const auto& func) {
    auto new_container = Container{};
    for(auto& item : container) {
        if(func(item)) {
            new_container.push_back(item);
        }
    }
    return new_container;
}

template<typename Container>
void print(const Container& cont) {
    for(const auto& item: cont) {
        cout << item << ", ";
    }
    cout << endl;
}


int main(int argc, char* argv[]) {

    return 0;
}