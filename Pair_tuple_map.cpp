// std::pair, std::tuple, std::map, structured binding
// std::tuple_element_t, std::get

// nth_type getter by variadic templates: nth_type<index, ...>
// nth_tuple_type getter: nth_tuple_type<index, tuple>

// static_assert(CompileTimeBooleanPredicate, error)

#include <iostream>
#include <map>

template <typename First, typename Second>
struct Pair {
    First first;
    Second second;
};

template <typename First, typename Second>
void print(const Pair<First,Second>& pair){
    std::cout << "(" << pair.first << ", " << pair.second << ")"<< std::endl;
}


void print(const std::map<auto, auto>& map) {
    for(const auto& [key, value]: map) {
        std::cout << key << " : " << value << std::endl;
    }
}

template <typename ... Params>
void print(const std::tuple<Params...>& tuple){
    const auto size = sizeof...(Params);
    ((std::cout << std::get<Params>(tuple) <<std::endl), ...);
}


int main (int argc, char* argv[]) {
    {
        auto pair_1 = Pair<int, double>{5, 6.7};
        print(pair_1);
        auto pair_2 = Pair<float, std::string>{3.14f, "Hello World!"};
        print(pair_2);
    }
    std::cout << "----" << std::endl;
    {
        auto map_1 = std::map<std::string, double>{
                {"BMW_320", 3.20},
                {"BMW_420", 4.20},
                {"BMW_530", 5.30}
        };
        print(map_1);
    }
    std::cout << "----" << std::endl;
    {
        std::tuple<int, double, std::string> tuple_1{5, 6.7, "Hello World!"};
        print(tuple_1);
    }
    std::cout << "----" << std::endl;

    return 0;
}