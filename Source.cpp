#include <iostream>
#include <vector>
#include <memory>
#include <random>

class Base {
public:
    virtual void show() const {
        std::cout << "Base class behavior" << std::endl;
    }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void show() const override {
        std::cout << "Derived class behavior" << std::endl;
    }
};

std::vector<std::unique_ptr<Base>> storage;

void add(std::unique_ptr<Base> obj) {
    storage.push_back(std::move(obj));
}

int main() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 9);


    for (int i = 0; i < 10; ++i) {
        int random_number = dist(gen);
        if (random_number % 2 == 0) {
            add(std::make_unique<Base>());
        }
        else {
            add(std::make_unique<Derived>());
        }
    }


    for (const auto& obj : storage) {
        obj->show();
    }

    return 0;
}
