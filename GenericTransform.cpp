#include <iostream>

/*
    vector: dynamic array structure
    - automatically manages the size of the array
    - random access ability using operator[]
    - supports random access iterators
    - random access: O(1), insertion or removal of elements at the end: O(1) amortized
    - insertion or removal of elements at the middle or beginning: O(N)
 */
#include <vector>

/*
    list: doubly linked list: each element points to the next and previous elements in the sequence
    - supports bidirectional iterators (forward and reverse)
    - lacks random access to elements
    - random access: O(n)
    - insertion or removal of elements at the middle or beginning: O(1)
 */
#include <list>

using namespace std;

template<typename Container, typename FuncObject>
void transform(Container& container, const FuncObject& funcObject) {
    for(auto& item : container) {
        item = funcObject(item);
    }
}

template<typename Container>
void print(const Container& container) {
    for(const auto& item : container)
        std::cout << item << ' ';
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    cout << "IntVector: " << endl;
    auto vector1 = vector<int>{1,2,3,4,5,6,7,8,9,10};
    print(vector1);

    cout << "IntList: " << endl;
    auto list1 = list<int>{10,20,30,40,50};
    print(list1);

    cout << "DoubleVector: " << endl;
    auto vector2 = vector<double>{1.1, 2.2, 3.3, 4.4, 5.5};
    print(vector2);

    cout << "DoubleList: " << endl;
    auto list2 = list<double>{10.1, 20.2, 30.3, 40.4, 50.5};
    print(list2);

    cout << "Transformations are happening!" << endl;
    transform(vector1, [](auto item) { return item*2; });
    transform(list1, [](auto item) { return item*2; });
    transform(vector2, [](auto item) { return item*2; });
    transform(list2, [](auto item) { return item*2; });
    cout << "Transformations end., Result: " << endl;

    print(vector1);
    print(list1);
    print(vector2);
    print(list2);

    return 0;
}