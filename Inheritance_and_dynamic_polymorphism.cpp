#include <iostream>
#include <string>

// Genus name: Panthera
struct Panthera {
    std::string name;
    std::string speciesName;

    Panthera() { std::cout << "I am Panthera. Just a Panthera!" << std::endl; };
    Panthera(const std::string& speciesName) : speciesName(speciesName) { };

    virtual void scientificName() {
        std::cout << "I am Panthera " << speciesName << "." << std::endl;
    }
};

// Species name: Pardus
struct Leopard : Panthera {
    Leopard(const std::string& speciesName) : Panthera(speciesName) { };

    void scientificName() override {
        std::cout << "I am Panthera " << speciesName << ". (Leopard)" << std::endl;
    }
};

// Species name: Leo
struct Lion : Panthera {
    Lion(const std::string& speciesName) : Panthera(speciesName) { };

    void scientificName() override {
        std::cout << "I am Panthera " << speciesName << ". (Lion)" << std::endl;
    }
};

// Species name: Onca
struct Jaguar : Panthera {
    Jaguar(const std::string& speciesName) : Panthera(speciesName) { };

    void scientificName() override {
        std::cout << "I am Panthera " << speciesName << ". (Jaguar)" << std::endl;
    }
};

// Species name: Tigris
struct Tiger : Panthera {
    Tiger(const std::string& speciesName) : Panthera(speciesName) { };

    void scientificName() override {
        std::cout << "I am Panthera " << speciesName << ". (Tiger)" << std::endl;
    }
};

int main(int argc, char* argv[]) {

    auto panthera_1 = Panthera();
    auto leopard = Leopard("Pardus");
    auto lion = Lion("Leo");
    auto jaguar = Jaguar("Onca");
    auto tiger = Tiger("Tigris");

    leopard.scientificName();
    lion.scientificName();
    jaguar.scientificName();
    tiger.scientificName();

    return 0;
}